describe('cd', function () {

  describe('$COOKIE_KEY', function () {

    beforeEach(module('cd'));

    it('should be defined', function () {
      inject(function ($COOKIE_KEY) {
        expect($COOKIE_KEY).toBeDefined();
      });
    });

    it('should be a string', function () {
      inject(function ($COOKIE_KEY) {
        expect(typeof $COOKIE_KEY).toBe('string');
      });
    });

    it('should return the cookie key', function () {
      inject(function ($COOKIE_KEY) {
        expect($COOKIE_KEY).toBe('NG_TRANSLATE_LANG_KEY');
      });
    });

  });

  describe('$translateService', function () {

    beforeEach(module('cd'));

    var $translate;

    beforeEach(inject(function (_$translate_) {
      $translate = _$translate_;
    }));

    it('should be defined', function () {
      inject(function ($translate) {
        expect($translate).toBeDefined();
      });
    });

    it('should be a function object', function () {
      inject(function ($translate) {
        expect(typeof $translate).toBe("function");
      });
    });

    it('should have a method uses()', function () {
      inject(function ($translate) {
        expect($translate.uses).toBeDefined();
      });
    });

    it('should have a method rememberLanguage()', function () {
      inject(function ($translate) {
        expect($translate.rememberLanguage).toBeDefined();
      });
    });

    describe('uses()', function () {

      it('should be a function', function () {
        inject(function ($translate) {
          expect(typeof $translate.uses).toBe('function');
        });
      });

      it('should return undefined if no language is specified', function () {
        inject(function ($translate) {
          expect($translate.uses()).toBeUndefined();
        });
      });

    });
  });

});
