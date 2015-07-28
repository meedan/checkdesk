<h3 class="component-heading"><?php print t('Most popular'); ?></h3>
<ul class="most-popular-items u-unstyled">
  <?php foreach ($stories as $id => $row): ?>
    <?php $has_image_class = (isset($row->image)) ? ' most-popular-item-has-image' : ''; ?>
    <li class="most-popular-item<?php print $has_image_class; ?>">
      <a class="most-popular-item-link" href="node/<?php print $row->nid; ?>">
        <?php if (isset($row->image)) : ?>
          <div class="most-popular-item-image">
            <figure class="media-lead">
              <?php print $row->image; ?>
            </figure>
          </div>
        <?php endif; ?>
        <h4 class="most-popular-item-headline"><?php print $row->title; ?></h4>
      </a>
    </li>
  <?php endforeach; ?>
</ul>