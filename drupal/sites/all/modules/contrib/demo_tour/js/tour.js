/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

jQuery(function () {
  'use strict';

  if (Drupal.settings.demoTour && window === window.parent) {

    var firstTour;
    var demoTours = [];
    
    // Generate a bootstrap-tour for each tour
    for (var tid in Drupal.settings.demoTour) {

      Drupal.settings.demoTour[tid].template = function(i, step) {
        var that = Drupal.settings.demoTour[step.tid];
        var html;
        html =  '<div class="popover tour-tour fade right in" id="step-' + i + '">';
        html += '  <div class="popover-arrow"></div>';
        html += '  <div class="popover-close" data-role="end"><span>[X]</span></div>';
        html += '  <h4><b>' + (i+1) + '</b> <span class="popover-title">' + step.title + '</span></h4>';
        html += '  <div class="popover-content"><p></p></div>';
        html += '  <div class="popover-navigation">';
        html += '    <ul>';

        for (var j = 0; j < that.steps.length; j++) {
          var classname = (j == i ? 'tour-current-step' : 'tour-step');
          html += '    <li onclick="Drupal.settings.demoTour.' + step.tid + '.tour.goTo(' + j + ')" class="' + classname + '">' + (j + 1) + '</li>';
        }
        
        html += '    </ul>';

        var label, role;
        if (i == (that.steps.length - 1)) {
          label = Drupal.t('Get started');
          role = 'end';
        }
        else {
          label = Drupal.t('Next');
          role = 'next';
        }

        html += '    <button data-role="' + role + '" class="tour-next">' + label + '</button>';
        html += '    <div class="popover-footer"></div>';
        html += '  </div>';
        html += '</div>';
        return html;
      };

      Drupal.settings.demoTour[tid].run = function() {
        var that = this;

        this.tour = new Tour({
          // TODO: Make some of these options configurable
          backdrop: true,
          redirect: false,
          orphan: true,
          container: '#main-body', // Protect iframes
          duration: false,
          template: this.template,
          onEnd: function(tour) {
            var next = demoTours.shift();
            if (next) {
              next.run();
            }
          },
          onShown: function(tour) {
            // If we set margin-left directly on CSS, it won't work on Firefox
            // FIXME: Argh, hard-coded
            jQuery('.tour-step-background').css('margin-left', '-200px');
            
            // Do not hide popovers on mouse over
            jQuery182('#' + this.id).off('mouseenter').off('mouseleave');
          }
        });

        this.tour.addSteps(this.steps);
        this.tour.init();
        
        try {
          this.tour.restart();
        } catch(e) {
          // Avoid errors with elements that were not completely loaded
        }
      };

      if (!firstTour) {
        firstTour = Drupal.settings.demoTour[tid];
      }
      else {
        demoTours.push(Drupal.settings.demoTour[tid]);
      }

    }

    jQuery(window).load(function() {
      firstTour.run();
    });

  }

});
