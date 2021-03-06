<?php

/**
 * @file
 * Sample template for sending user password reset messages with HTML Mail
 *
 * The following variables are available in this template:
 *
 *  - $message_id: The email message id, which is 'user_password_reset'
 *  - $module: The sending module, which is 'user'.
 *  - $key: The user email action, which is 'password_reset'.
 *  - $headers: An array of email (name => value) pairs.
 *  - $from: The configured sender address.
 *  - $to: The recipient email address.
 *  - $subject: The message subject line.
 *  - $body: The formatted message body.
 *  - $language: The language object for this message.
 *  - $params: An array containing the following keys:
 *    - account: The user object whose password is being requested, which
 *      contains the following useful properties:
 *      - uid: The user-id number.
 *      - name: The user login name.
 *      - mail: The user email address.  Should be the same as $to.
 *      - theme: The user-chosen theme, or a blank string if unset.
 *      - signature: The user signature block.
 *      - signature_format: The text input filter used to format the signature.
 *      - created: Account creation date, as a unix timestamp.
 *      - access: Account access date, as a unix timestamp.
 *      - login: Account login date, as a unix timestamp.
 *      - status: Integer 0 = disabled; 1 = enabled.
 *      - timezone: User timezone, or NULL if unset.
 *      - language: User language, or blank string if unset.
 *      - picture: Path to user picture, or blank string if unset.
 *      - init: The email address used to initially register this account.
 *      - data: User profile data, as a serialized string.
 *      - roles: Array of roles assigned to this user, as (rid => role_name)
 *        pairs.
 *  - $template_path: The relative path to the template directory.
 *  - $template_url: The absolute url to the template directory.
 *  - $theme: The name of the selected Email theme.
 *  - $theme_path: The relative path to the Email theme directory.
 *  - $theme_url: The absolute url to the Email theme directory.
 */
$logo_path = theme_get_setting('header_image_path');
$image = empty($logo_path) ? '' : image_style_url('partner_logo', $logo_path);

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
                <p class="aligncenter"
                   style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; font-weight: normal; margin: 0 0 10px; padding: 0; text-align: center"
                   align="center">
                  <?php print t('You can follow'); ?>
                  <a href="http://twitter.com/checkdesk"
                     style="box-sizing: border-box; color: #999; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0; text-decoration: underline">
                    <?php print t('@Checkdesk on Twitter'); ?></a>.
                </p>

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
