(function(){
    CKEDITOR.on('instanceReady', function(e){
        var instance = e.editor;

        // control code formatting for some html elements to prevent extra line breaks
        var rules = {
                indent : false,
                breakBeforeOpen : false,
                breakAfterOpen : false,
                breakBeforeClose : false,
                breakAfterClose : true
            }
        instance.dataProcessor.writer.setRules('p', rules);
        instance.dataProcessor.writer.setRules('div', rules);
        instance.dataProcessor.writer.setRules('figure', rules);

        //catch ctrl+clicks on <a>'s in edit mode to open hrefs in new tab/window
        jQuery('iframe').contents().click(function(el) {  
          el.target.title = Drupal.t('Press Ctrl + click to open the link');
          if(typeof el.target.href != 'undefined' && el.ctrlKey == true) {          
            window.open(el.target.href, 'new' + el.screenX);
          }
        });
    });
})();
