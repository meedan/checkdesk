describe('cd', function () {

  describe('cd.csrfToken.config', function () {

    beforeEach(module('cd'));

    var $httpProviderDefaults;

    beforeEach(module('cd.csrfToken', function ($httpProvider) {
      $httpProviderDefaults = $httpProvider.defaults;
    }));

    it('$httpProvider.xsrf* should be configured', function () {
      inject(function () {
        expect($httpProviderDefaults.xsrfCookieName).toBe('CSRF-Token');
        expect($httpProviderDefaults.xsrfHeaderName).toBe('X-CSRF-Token');
      });
    });

  });

});
