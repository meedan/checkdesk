/**
* Provide the HTML to create the modal dialog.
*/
Drupal.theme.prototype.CToolsSampleModal = function () {
  var html = '';


  html += '<div id="ctools-modal">';
  html += '<div class="ctools-modal-content ctools-sample-modal-content">';
  html += '<div class="modal">';
  html += '  <div class="modal-header">';
  html += '   <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>';
  html += '   <h3><span id="modal-title" class="modal-title"></span></h3>';
  html += '  </div>';
  html += ' <div class="modal-body">';
  html += '   <p><div id="modal-content" class="modal-content popups-body"></div></p>';
  html += ' </div>';
  html += ' <div class="modal-footer">';
  html += '   <a href="#" class="btn">Close</a>';
  html += '   <a href="#" class="btn btn-primary">Save changes</a>';
  html += ' </div>';
  html += '</div>';
  html += '</div>';
  html += '</div>';

  return html;

}
