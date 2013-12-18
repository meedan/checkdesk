/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

jQuery(function () {
  'use strict';

  if (Drupal.settings.checkdeskTour && window === window.parent) {

    var firstTour;
    var checkdeskTours = [];
    
    // Generate a bootstrap-tour for each tour
    for (var tid in Drupal.settings.checkdeskTour) {

      Drupal.settings.checkdeskTour[tid].template = function(i, step) {
        var that = Drupal.settings.checkdeskTour[step.tid];
        var html;
        html =  '<div class="popover tour-tour fade right in" id="step-' + i + '">';
        html += '  <div class="popover-arrow"></div>';
        html += '  <div class="popover-close" data-role="end"><span>[X]</span></div>';
        html += '  <h3><b>' + (i+1) + '</b> <span class="popover-title">' + step.title + '</span></h3>';
        html += '  <div class="popover-content">' + step.content + '</div>';
        html += '  <div class="popover-navigation">';
        html += '    <ul>';

        for (var j = 0; j < that.steps.length; j++) {
          var classname = (j == i ? 'tour-current-step' : 'tour-step');
          html += '    <li onclick="Drupal.settings.checkdeskTour.' + step.tid + '.tour.goTo(' + j + ')" class="' + classname + '"></li>';
        }
        
        html += '    </ul>';

        var label, role;
        if (i == (that.steps.length - 1)) {
          label = Drupal.t('Get started');
          role = 'end';
        }
        else {
          label = Drupal.t('Next - <span>@step</span>', { '@step' : that.steps[i+1].title });
          role = 'next';
        }

        html += '    <button data-role="' + role + '" class="tour-next">' + label + '</button>';
        html += '    <div class="popover-footer"></div>';
        html += '  </div>';
        html += '</div>';
        return html;
      };

      Drupal.settings.checkdeskTour[tid].run = function() {
        var that = this;

        this.tour = new Tour({
          // TODO: Make some of these options configurable
          backdrop: true,
          redirect: false,
          orphan: true,
          container: '#main-body', // Protect iframes
          duration: 6000,
          template: this.template,
          onEnd: function(tour) {
            var next = checkdeskTours.shift();
            if (next) {
              next.run();
            }
          },
          onShown: function(tour) {
            // If we set margin-left directly on CSS, it won't work on Firefox
            // FIXME: Argh, hard-coded
            jQuery('.tour-step-background').css('margin-left', '-200px');
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
        firstTour = Drupal.settings.checkdeskTour[tid];
      }
      else {
        checkdeskTours.push(Drupal.settings.checkdeskTour[tid]);
      }

    }

    jQuery(window).load(function() {
      firstTour.run();
    });

  }

});
