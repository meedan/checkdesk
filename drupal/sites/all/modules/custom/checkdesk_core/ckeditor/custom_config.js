(function(){
    CKEDITOR.on('instanceReady', function(e){
        var instance = e.editor;

        // control code formatting for some hrml elements to prevent extra line breaks
        var rules = {
                indent : false,
                breakBeforeOpen : false,
                breakAfterOpen : false,
                breakBeforeClose : false,
                breakAfterClose : true
            }
        instance.dataProcessor.writer.setRules( 'p',rules);
        instance.dataProcessor.writer.setRules( 'div',rules);
        instance.dataProcessor.writer.setRules( 'figure',rules);
    });
})();
