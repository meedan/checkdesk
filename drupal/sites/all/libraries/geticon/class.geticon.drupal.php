<?php

/**
 * geticon.org's favicon to social icon (png) converting class
 *
 * the class find favicons of websites and converts them to PNG files for using
 * as a social icon. 
 *
 * PHP version 5
 *
 * LICENSE: Distributed under the General Public License (GPL)
 * http://www.gnu.org/copyleft/gpl.html
 * This program is distributed in the hope that it will be useful - WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * @author     goker cebeci
 * @license    http://www.gnu.org/copyleft/gpl.html GPL License 3
 * @link       http://geticon.org
 * @return     PNG file
 */
class geticon {

    private $_url = '';
    private $_default = ''; // default icon
    private $_cache_name = '';
    private $_ico_url = '';
    private $_logdata;

    /**
     *
     * @param type $url
     * @param type $root
     * @param type $cache_folder 
     */
    public function __construct($url, $root, $cache_folder) {
        //$this->_default = $root . $cache_folder . 'default.png';
        $this->_default = drupal_get_path('module', 'meedan_oembed') .'/theme/thumbnail.png';
        $url = trim(str_replace(array('http://', 'https://', 'http:/', 'https:/'), '', trim($url)), '/');
        $url = parse_url('http://' . $url);
        $url['host'] = str_replace('www.', '', $url['host']);
        $this->_url = 'http://' . $url['host'] . '/';
        $this->_cache_name = $root . $cache_folder . str_replace(array('.', '/'), '-', $url['host']);
        if (!($this->cache = is_file($this->_cache_name . '.png')) || (isset($_REQUEST['cache']) && !$_REQUEST['cache'])) {
            $this->_catch();
            $this->_copy();
            //$this->_convert(false);
        }
        //$this->_show();
    }

    /**
     * catching favicon link
     * 
     * @param boolean $linktag 
     */
    private function _catch($linktag = true) {
        if ($this->_url) {
            $this->_log('Date', @date(DATE_RFC822));
            $this->_log('URL', $this->_url);
            $this->_log('Open Document', $this->_url);
            if ($linktag) {
                $h = @fopen($this->_url, 'r');
                if ($h) {
                    $html = file_get_contents($this->_url);
                    $this->_log('Search `link` tag', $this->_url);
                    if (preg_match('/<([^>]*)link([^>]*)rel\=("|\')?(icon|shortcut icon)("|\')?([^>]*)>/iU', $html, $out)) {
                        $this->_log('Favicon Tag', htmlentities($out[0]));
                        if (preg_match('/href([s]*)=([s]*)"([^"]*)"/iU', $out[0], $out)) {
                            $ico_href = trim($out[3]);
                            if (preg_match('/(http)(s)?(:\/\/)/', $ico_href, $matches, PREG_OFFSET_CAPTURE)) {
                                $this->_ico_url = $ico_href;
                            } elseif (preg_match('/(\/\/)/', $ico_href, $matches, PREG_OFFSET_CAPTURE)) {
                                $this->_ico_url = 'http:' . $ico_href;
                            } else
                                $this->_ico_url = $this->_url . '/' . ltrim($ico_href, '/');
                            $this->_log('Favicon Tag href', $out[3]);
                        }
                    } else
                        $this->_log('Not Found `link` Tag', $this->_url);
                }
                $this->_ico_url = $this->_ico_url ? $this->_ico_url : $this->_url . 'favicon.ico';
            } else
                $this->_ico_url = $this->_url . 'favicon.ico';
            $this->_log('Favicon URL', $this->_ico_url);
            $drupal_headers = drupal_http_request($this->_ico_url,array('method' => 'HEAD'));
            $headers  = $drupal_headers->headers;
            $this->_log('Favicon Headers', $headers);
            if (isset($headers['location'])) {
                $headers['location'] = is_array($headers['location']) ? end($headers['location']) : $headers['location'];
                $this->_log('Redirect Location', $headers['location']);
                $this->_ico_url = $headers['location'];
                //$this->_log('Favicon Headers', $headers);
            }
            if ($drupal_headers->code == 200 || $drupal_headers->code == 302) {
                //$this->_log('Favicon Header Content Type', $headers['Content-Type']);
            } else {
                if ($this->_ico_url != $this->_url . 'favicon.ico' && $linktag) {
                    $this->_catch(false);
                } else {
                    //$this->_log('Unknown Favicon', $headers['Content-Type']);
                    $this->_ico_url = $this->_default;
                }
            }
        }
    }

    /**
     * copying favicon file
     */
    private function _copy() {
        $this->_log('Favicon URL', $this->_ico_url);
        if ($this->_ico_url == $this->_default) {
            $this->_log('Copy Default Icon', $this->_default);
            copy($this->_default, $this->_cache_name . '.ico');
        } else
            $icofile = $this->_cache_name . '.ico';

        try {
            $this->_log('Favicon Cache', $icofile);
            file_put_contents($icofile, file_get_contents($this->_ico_url));
            // CHECK MIMETYPE
            $finfo = new finfo(FILEINFO_MIME, "/usr/share/misc/magic");
            $type = $finfo->file($icofile);
            $this->_log('Favicon Fileinfo Content Type', $type);
            if (!preg_match('/(image|ico|octet-stream|icon)/', $type, $matches, PREG_OFFSET_CAPTURE)) {
                $this->_log('Copy Default Icon', $this->_default);
                copy($this->_default, $icofile);
            } else {
                $this->_log('Saved ICO', $icofile);
            }
        } catch (Exception $e) {
            $this->_log('Caught exception', $e->getMessage());
            $this->_log('Copy Default Icon', '');
            copy($this->_default, $icofile);
        }
    }

    /**
     * converting ico to png
     * 
     * @param boolean $error 
     */
    private function _convert($error = false) {
        try {
            $source = ((!is_file($this->_cache_name . '.ico') || $error) ? $this->_default : $this->_cache_name . '.ico');
            exec('identify -verbose "' . $source . '"', $r);
            $this->_log('Identify -verbose', $r);
            $cmd = 'convert "' . $source . '" -thumbnail 16x16 -alpha on -background none -flatten "' . $this->_cache_name . '.png"';
            $this->_log('Convert CMD', $cmd);
            exec($cmd, $r);
        } catch (Exception $e) {
            $this->_log('Convert problem: ' . $e->getMessage() . "\n");
            file_put_contents($this->_cache_name . '.log', json_encode($this->_logdata));
        }
        if (!is_file($this->_cache_name . '.png')) {
            $this->_log('Convert problem:', $r);
            $this->_log('Copy Default Icon', $this->_default);
            copy($this->_default, $this->_cache_name . '.png');
        }
        $this->_log('Cached Icon', $this->_cache_name . '.png');
        file_put_contents($this->_cache_name . '.log', json_encode($this->_logdata));
    }

    /**
     * showing png file
     */
    public function _show() {
        header('Content-type: image/png');
        echo file_get_contents($this->_cache_name . '.png');
    }

    /**
     * logging
     * 
     * @param string $label
     * @param string $msg 
     */
    private function _log($label, $msg) {
        //error_log($label . ' : ' . print_r($msg, 1));
        if (variable_get('checkdesk_favicon_log', FALSE)) {
          $this->_logdata[$label] = $msg;
        }
    }

}