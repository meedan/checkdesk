<section id="node-<?php print $node->nid; ?>" class="default-view-node-<?php print $node->nid; ?> item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
    <article class="report item <?php if (isset($status_class)) { print $status_class; } ?>">

        <h1 class="title">
            <?php print l(render($node->title), 'node/'. $node->nid); ?>
        </h1>

        <?php if(isset($content['field_tags'])) : ?>
            <?php print render($content['field_tags']); ?>
        <?php endif ?>

        <?php print render($content['field_link']); ?>

        <div class="item-wrapper">
            <?php print $report_activity; ?>

        </div>
    </article>


</section>
