<div class="desk" style="clear: both;">
  <article class="story">
    <h1>
      <span class="field-content">
        <?php print l($fields['title']->raw, 'node/' . $fields['nid']->raw); ?>
      </span>
    </h1>

    <div class="story-body">
      <?php render($fields['body']->content); ?>
    </div>

    <?php print $updates; ?>
  </article>
</div>
