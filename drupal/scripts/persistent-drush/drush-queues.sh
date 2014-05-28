#!/bin/bash

# drush queue runs for clearing varnish cash and for email delivery
# queues are populated after content updates
# http://mantis.meedan.net/view.php?id=2976#c7977

# melsawy and bfoote
# 2014-05-28

# run from supervisor

# ALIAS is one of @checkdesk.dev @checkdesk.qa @checkdesk.prod
ALIAS=$1

while true;
do
   drush $ALIAS -y queue-run checkdesk_varnish;
   drush $ALIAS -y queue-run rules_scheduler_tasks;
   sleep 20;
done