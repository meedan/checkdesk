#!/bin/bash

# install script for drush-queues.sh
# http://mantis.meedan.net/view.php?id=2976#c7977

LINK=$1;

if [ "" = "${LINK}" ]
then
    cat <<EOF

    usage:
       sudo $0 supervisor.conf.devel

       sets up environment for running drush-queues.sh from supervisor
EOF

    exit;
fi

apt-get install -qy supervisord
ln -s ${PWD}/supervisor.conf ${PWD}/$LINK
ln -s /etc/supervisor/conf.d/drush-queues.conf ${PWD}/supervisor.conf
ln -s /usr/local/bin/drush-queues.sh ${PWD}/drush-queues.sh