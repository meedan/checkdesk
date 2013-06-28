describe('cd', function () {

  describe('app', function () {

    beforeEach(module('cd'));

    it('should be globally defined', function () {
      inject(function () {
        expect(app).toBeDefined();
      });
    });

    it('should be a global object', function () {
      inject(function () {
        expect(typeof app).toBe('object');
      });
    });

  });

});
