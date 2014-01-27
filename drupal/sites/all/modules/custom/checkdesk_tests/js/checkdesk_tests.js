/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

jQuery(function($) {
  'use strict';

  var checkStatus = function() { 
    var $stat = $('#checkdesk-tests-status'),
        $output = $('#checkdesk-tests-output');

    $.ajax({
      url: Drupal.settings.basePath + 'checkdesk-tests/status?' + parseInt(Math.random() * 1000000000, 10),
      dataType: 'json',
      success: function (data) {
        $stat.removeClass('running');

        if (data.running) {
          $stat.addClass('running');
          $stat.find('span').html(Drupal.t('Running'));
          setTimeout(checkStatus, 10000);
        } else {
          $stat.find('span').html(Drupal.t('Not running'));
        }

        $output.html(data.output);
        $output[0].scrollTop = $output[0].scrollHeight;
      },
      error: function (xhr, textStatus, error) {
        console.log(Drupal.t('An error happened on checking tests status.'));
        setTimeout(checkStatus, 10000);
      }
    });
  }
  checkStatus();
});
