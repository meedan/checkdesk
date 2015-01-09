<?php
/**
 * @file
 * Checkdesk template for notifications mail
 */
// set checkdesk log
$logo_path = theme_get_setting('header_image_path');
$image = empty($logo_path) ? '' : image_style_url('partner_logo', $logo_path);
$account = $params['account'];
$languages = language_list();
$recipient_url = url("user/{$account->uid}/edit", array('language' => $languages[$account->language], 
                    'absolute' => TRUE, 'alias' => TRUE));
$footer = array();

$footer[] = t('You can edit your notification settings from your <a href="!recipient_url">profile page</a>.', array('!recipient_url' => $re    cipient_url), array('langcode' => $account->language));

$footer[] = t('You can follow <a href="!link"> @Checkdesk on Twitter </a>.', array('!link' => 'http://twitter.com/checkdesk'), array('langc    ode' => $account->language));

$footer[] = t('This was an auto-generated email from !site; please do not respond directly to this email.', 
                               array('!site' =>  variable_get('site_name', 'Checkdesk')), array('langcode' => $account->language));
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns="http://www.w3.org/1999/xhtml"
      style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
<head>
  <meta name="viewport" content="width=device-width"/>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <title>Hello from Checkdesk</title>
</head>
<body
  style="-webkit-font-smoothing: antialiased; -webkit-text-size-adjust: none; background: #f6f6f6; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; height: 100%; line-height: 1.6; margin: 0; padding: 0; width: 100% !important"
  bgcolor="#f6f6f6">
<style type="text/css">
  img {
    max-width: 100%;
  }

  body {
    -webkit-font-smoothing: antialiased;
    -webkit-text-size-adjust: none;
    width: 100% !important;
    height: 100%;
    line-height: 1.6;
  }

  body {
    background-color: #f6f6f6;
  }

  a {
    box-sizing: border-box; 
    color: #999; 
    font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif;
    font-size: 12px; 
    margin: 0; 
    padding: 0; 
    text-decoration: underline;
  }

  @media only screen and (max-width: 600px) {
    h1 {
      font-weight: 600 !important;
    }

    h2 {
      font-weight: 600 !important;
    }

    h3 {
      font-weight: 600 !important;
    }

    h4 {
      font-weight: 600 !important;
    }

    h1 {
      font-size: 22px !important;
    }

    h2 {
      font-size: 18px !important;
    }

    h3 {
      font-size: 16px !important;
    }

    .content {
      padding: 10px !important;
    }

    .content-wrapper {
      padding: 10px !important;
    }

    .invoice {
      width: 100% !important;
    }
  }
</style>

<table class="body-wrap"
       style="background: #f6f6f6; border-collapse: collapse; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; width: 100%"
       bgcolor="#f6f6f6">
  <tr
    style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
    <td
      style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top"
      valign="top"></td>
    <td class="container"
        style="box-sizing: border-box; clear: both !important; display: block !important; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 600px !important; padding: 0; vertical-align: top"
        valign="top">
      <div class="content"
           style="box-sizing: border-box; display: block; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 600px; padding: 20px">
        <table class="main" width="100%"
               style="background: #fff; border-collapse: collapse; border-radius: 3px; border: 1px solid #e9e9e9; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 0 20px; padding: 0"
               bgcolor="#fff">
          <tr
            style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
            <td
              style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top"
              valign="top">
              <?php if ($image) : ?>
                <img id="logo" src="<?php print $image ?>"
                   style="box-sizing: border-box; display: block; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 100%; padding: 10px; width: 20%"/>
              <?php endif; ?>
            </td>
          </tr>
          <tr
            style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
            <td class="content-wrapper"
                style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 20px; vertical-align: top"
                valign="top">
              <div class="htmlmail-body" dir="<?php echo $direction; ?>">
                <?php echo $body; ?>
              </div>
            </td>
          </tr>
        </table>
        <div class="footer"
             style="box-sizing: border-box; clear: both; color: #666; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; width: 100%">
          <table width="100%"
                 style="border-collapse: collapse; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
            <tr
              style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
              <td
                style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top"
                valign="top">
                <!--
                				<p class="aligncenter" style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; font-weight: normal; margin: 0 0 10px; padding: 0; text-align: center" align="center">Don't like these emails? <a href="#" style="box-sizing: border-box; color: #999; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0; text-decoration: underline"><unsubscribe style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0">Unsubscribe</unsubscribe></a>.
                </p>
                -->
                <?php foreach ($footer as $f_row) : ?>
                <p class="aligncenter"
                   style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; font-weight: normal; margin: 0 0 10px; padding: 0; text-align: center"
                   align="center">
                  <?php print $f_row; ?>
                </p>
                <?php endforeach; ?>
              </td>
            </tr>
          </table>
        </div>
      </div>
    </td>
    <td
      style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top"
      valign="top"></td>
  </tr>
</table>
</body>
</html>
