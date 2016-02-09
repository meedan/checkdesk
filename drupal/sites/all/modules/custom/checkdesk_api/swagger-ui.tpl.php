<!DOCTYPE html>
<html>
<head>
  <title>Checkdesk API</title>
  <link href='//fonts.googleapis.com/css?family=Droid+Sans:400,700' rel='stylesheet' type='text/css' />

  <?php foreach (array('highlight.default', 'screen') as $style) { ?>
    <link href='<?php print $base . '/swagger-ui/css/' . $style; ?>.css' media='screen' rel='stylesheet' type='text/css' />
  <?php } ?>

  <?php foreach (array('shred.bundle', 'jquery-1.8.0.min', 'jquery.slideto.min', 'jquery.wiggle.min', 'jquery.ba-bbq.min', 'handlebars-1.0.0', 'underscore-min', 'backbone-min', 'swagger', 'highlight.7.3.pack') as $script) { ?>
    <script src='<?php print $base . '/swagger-ui/lib/' . $script; ?>.js' type='text/javascript'></script>
  <?php } ?>

  <script src='<?php print $base; ?>/swagger-ui/swagger-ui.js' type='text/javascript'></script>

  <script type="text/javascript">
    $(function () {
      window.swaggerUi = new SwaggerUi({
      url: "/checkdesk-api/docs/api",
      dom_id: "swagger-ui-container",
      supportedSubmitMethods: ['get', 'post', 'put', 'delete'],
      onComplete: function(swaggerApi, swaggerUi){
        if (console) {
          console.log("Loaded SwaggerUI")
        }
        $('pre code').each(function(i, e) {hljs.highlightBlock(e)});
      },
      onFailure: function(data) {
        if (console) {
          console.log("Unable to Load SwaggerUI");
          console.log(data);
        }
      },
      docExpansion: "full"
    });

    $('#input_apiKey').change(function() {
      var key = $('#input_apiKey')[0].value;
      console.log("key: " + key);
      if (key && key.trim() != "") {
        console.log("added key " + key);
        window.authorizations.add("key", new ApiKeyAuthorization("Authorization", 'Token token="' + key + '"', "header"));
      }
    })
    window.swaggerUi.load();
  });

  </script>
</head>

<body>
<div id='header'>
  <div class="swagger-ui-wrap">
    <a id="logo" href="https://github.com/meedan/checkdesk">Checkdesk</a>

    <form id='api_selector'>
      <div class='input'><input placeholder="/api" id="input_baseUrl" name="baseUrl" type="text"/></div>
      <div class='input'><input placeholder="api_key" id="input_apiKey" name="apiKey" type="text"/></div>
      <div class='input'><a id="explore" href="#">Explore</a></div>
    </form>
  </div>
</div>

<div id="message-bar" class="swagger-ui-wrap">
</div>

<div id="swagger-ui-container" class="swagger-ui-wrap">

</div>

</body>

</html>
