<?php if (count($metadata_fields)) : ?>

    <div id="report-metadata-<?php print $node->nid; ?>" class="report-metadata report-metadata-node-<?php print $node->nid; ?> ">

        <?php foreach ($metadata_fields as $field): ?>
            <?php if (isset($field)) : ?>
                <div class="cd-metadata-field">
                    <?php print render($field); ?>
                </div>
            <?php endif; ?>
        <?php endforeach; ?>

    </div>

<?php endif; ?>