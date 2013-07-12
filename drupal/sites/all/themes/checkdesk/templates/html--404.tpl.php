<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
    <head>
        <meta charset="utf-8" />
        <!--[if IE 8]> <meta http-equiv="X-UA-Compatible" content="IE=8" />  <![endif]-->
        <!--[if gt IE 8]><!--> <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" /> <!--<![endif]-->
        <title><?php print $head_title; ?></title>
        <meta name="description" content="" />
        <meta name="viewport" content="width=device-width" />
        <?php print $head; ?>
        <?php // print $scripts; ?>
        <?php // print $styles; ?>
        <style>
            body{
                margin: 0 0 0 0;
                padding: 0 0 0 0;
                background: url(pattern.png) repeat;
            }

            h1{
                font-weight: normal;
                font-size: 72px;
                color: #515151;
                text-shadow: #fff 1px 1px 1px;
                margin: 0 0 0 0;
            }


            h3{
                font-size: 38px;
                font-family: Georgia, "Times New Roman", Times, serif;
                font-weight: normal;
                color: #8d8d8d;
                margin: 0 0 0 0;
                letter-spacing: -1px;
            }


            p{
                font-family: Georgia, "Times New Roman", Times, serif;
                font-size: 18px;
                line-height: 26px;
                color: #8d8d8d;
            }


            #top{
                background-color: #333;
                color: #ddd;
                height: 3em;
                line-height: 3em;
                text-align: center;
                font-size: 0.8em;
            }

            #header{
                width: 700px;
                display: block;
                margin-left: auto;
                margin-right: auto;
                padding: 100px 0px 30px 0px;
                border-bottom: solid 2px #515151;
            }

            #main{
                width: 700px;
                display: block;
                margin-left: auto;
                margin-right: auto;
            }

            a{
                text-decoration: none;  
            }


            a.checkdesk{
                color: #515151;
            }

            .separator {
                width: 100%;
                height: 2px;
                color: #515151;
                display: block;
            }
        </style>
    </head>
    <body class="<?php print $classes; ?>">
        <div class="page-container">
            <!--[if lt IE 7]>
                <p class="chromeframe">You are using an outdated browser. <a href="http://browsehappy.com/">Upgrade your browser today</a> or <a href="http://www.google.com/chromeframe/?redirect=true">install Google Chrome Frame</a> to better experience this site.</p>
            <![endif]-->
            <?php // print $page_top; ?>
            <?php print $page; ?>
            <?php // print $page_bottom; ?>
        </div>
    </body>
</html>