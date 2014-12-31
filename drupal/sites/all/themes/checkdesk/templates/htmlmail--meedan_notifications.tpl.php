<?php
/**
 * @file
 * Checkdesk template for notifications mail
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns="http://www.w3.org/1999/xhtml" style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0">
  <head>
    <meta name="viewport" content="width=device-width" />
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>Hello from Checkdesk</title>
  </head>
  <body style="-webkit-font-smoothing: antialiased; -webkit-text-size-adjust: none; background: #f6f6f6; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; height: 100%; line-height: 1.6; margin: 0; padding: 0; width: 100% !important" bgcolor="#f6f6f6"><style type="text/css">
img {
max-width: 100%;
}
body {
-webkit-font-smoothing: antialiased; -webkit-text-size-adjust: none; width: 100% !important; height: 100%; line-height: 1.6;
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

<table class="body-wrap" style="background: #f6f6f6; border-collapse: collapse; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; width: 100%" bgcolor="#f6f6f6"><tr style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0"><td style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top" valign="top"></td>
		<td class="container" style="box-sizing: border-box; clear: both !important; display: block !important; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 600px !important; padding: 0; vertical-align: top" valign="top">
			<div class="content" style="box-sizing: border-box; display: block; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 600px; padding: 20px">
				
<table class="main" width="100%" style="background: #fff; border-collapse: collapse; border-radius: 3px; border: 1px solid #e9e9e9; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 0 20px; padding: 0" bgcolor="#fff"><tr style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0"><td style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top" valign="top">

		<img id="logo" src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAlgAAABvCAMAAAAHWE7SAAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAyZpVFh0WE1MOmNvbS5hZG9iZS54bXAAAAAAADw/eHBhY2tldCBiZWdpbj0i77u/IiBpZD0iVzVNME1wQ2VoaUh6cmVTek5UY3prYzlkIj8+IDx4OnhtcG1ldGEgeG1sbnM6eD0iYWRvYmU6bnM6bWV0YS8iIHg6eG1wdGs9IkFkb2JlIFhNUCBDb3JlIDUuNS1jMDIxIDc5LjE1NTc3MiwgMjAxNC8wMS8xMy0xOTo0NDowMCAgICAgICAgIj4gPHJkZjpSREYgeG1sbnM6cmRmPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5LzAyLzIyLXJkZi1zeW50YXgtbnMjIj4gPHJkZjpEZXNjcmlwdGlvbiByZGY6YWJvdXQ9IiIgeG1sbnM6eG1wPSJodHRwOi8vbnMuYWRvYmUuY29tL3hhcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RSZWY9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZVJlZiMiIHhtcDpDcmVhdG9yVG9vbD0iQWRvYmUgUGhvdG9zaG9wIENDIDIwMTQgTWFjaW50b3NoIiB4bXBNTTpJbnN0YW5jZUlEPSJ4bXAuaWlkOkNCNDA0RUY5MUIzQTExRTQ5MjlDQTRDMUFEQzdCMDk4IiB4bXBNTTpEb2N1bWVudElEPSJ4bXAuZGlkOkNCNDA0RUZBMUIzQTExRTQ5MjlDQTRDMUFEQzdCMDk4Ij4gPHhtcE1NOkRlcml2ZWRGcm9tIHN0UmVmOmluc3RhbmNlSUQ9InhtcC5paWQ6Q0I0MDRFRjcxQjNBMTFFNDkyOUNBNEMxQURDN0IwOTgiIHN0UmVmOmRvY3VtZW50SUQ9InhtcC5kaWQ6Q0I0MDRFRjgxQjNBMTFFNDkyOUNBNEMxQURDN0IwOTgiLz4gPC9yZGY6RGVzY3JpcHRpb24+IDwvcmRmOlJERj4gPC94OnhtcG1ldGE+IDw/eHBhY2tldCBlbmQ9InIiPz4Z8lXiAAAAMFBMVEXrzWnj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" style="box-sizing: border-box; display: block; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0 auto; max-width: 100%; padding: 10px; width: 60%" /></td>
	</tr><tr style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0"><td class="content-wrapper" style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 20px; vertical-align: top" valign="top">

<div class="htmlmail-body" dir="<?php echo $direction; ?>">
  <?php echo $body; ?>
</div>

		</td>
	</tr></table><div class="footer" style="box-sizing: border-box; clear: both; color: #666; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; width: 100%">
	<table width="100%" style="border-collapse: collapse; box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0"><tr style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0"><td style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top" valign="top">
				<p class="aligncenter" style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; font-weight: normal; margin: 0 0 10px; padding: 0; text-align: center" align="center">Don't like these emails? <a href="#" style="box-sizing: border-box; color: #999; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0; text-decoration: underline"><unsubscribe style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0">Unsubscribe</unsubscribe></a>.
				</p><p class="aligncenter" style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; font-weight: normal; margin: 0 0 10px; padding: 0; text-align: center" align="center">You can follow <a href="http://twitter.com/checkdesk" style="box-sizing: border-box; color: #999; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 12px; margin: 0; padding: 0; text-decoration: underline">@Checkdesk on Twitter</a>.</p>
				
			</td>
		</tr></table></div>
			</div>
		</td>
		<td style="box-sizing: border-box; font-family: 'Helvetica Neue', 'Helvetica', Helvetica, Arial, sans-serif; font-size: 14px; margin: 0; padding: 0; vertical-align: top" valign="top"></td>
	</tr></table></body>
</html>
