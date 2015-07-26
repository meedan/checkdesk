<h2><?php print t('Most popular'); ?></h2>
<ul class="">
    <?php foreach ($stories as $id => $row): ?>
        <li class="cd-slice-item l-row-item-span-1">
            <?php $has_image_class = (isset($row->image)) ? ' cd-item-has-image' : ''; ?>
            <div class="cd-item tone-default-item <?php print $has_image_class; ?>">
                <div class="">
                    <?php if (isset($row->image)) : ?>
                        <div class="cd-item-media-wrapper">
                            <div class="cd-item-image-container u-responsive-ratio">
                                <figure class="media-lead">
                                    <?php print $row->image; ?>
                                </figure>
                            </div>
                        </div>
                    <?php endif; ?>
                    <div class="cd-item-content">
                        <div class="cd-item-header">
                            <h2 class="cd-item-title"><?php print $row->title; ?></h2>
                        </div>
                    </div>
                </div>
            </div>
        </li>
    <?php endforeach; ?>
</ul>