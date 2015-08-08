
<?php if (count($rows) == 4): ?> 
    <ul class="cd-slice l-row l-row-cols-4 u-unstyled">
        <?php foreach ($rows as $id => $row): ?>
            <li class="cd-slice-item l-row-item l-row-item-span-1<?php if ($classes_array[$id]) {
            print ' ' . $classes_array[$id];
        } ?>">
            <?php print $row; ?>
            </li>
    <?php endforeach; ?>
    </ul>
        <?php else : ?>
    <div class="cd-linkslist-container">
        <ul class="cd-slice cd-linkslist l-list l-list--columns-4 u-unstyled">
                <?php foreach ($rows as $id => $row): ?>
                <li class="cd-slice-item l-list-item l-list-item-span-1<?php if ($classes_array[$id]) {
                print ' ' . $classes_array[$id];
            } ?>">
        <?php print $row; ?>
                </li>
    <?php endforeach; ?>
        </ul>
    </div>
<?php endif; ?>

