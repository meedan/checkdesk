<?php if(isset($activity_status)) : ?>
<div class="checkdesk-report-activity-status-wrapper">
 <?php print $activity_status; ?>
 <?php if(isset($activity_status_footnote)) :  ?>
   <div calss="checkdesk-activity-status-footnote" >
       <?php print $activity_status_footnote; ?>
   </div>
 <?php endif; ?>
</div>
<?php endif; ?>


