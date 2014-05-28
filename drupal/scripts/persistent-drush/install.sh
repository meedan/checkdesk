#!/bin/bash

# install script for drush-queues.sh
# http://mantis.meedan.net/view.php?id=2976#c7977

# bfoote
# 2014-05-28

CONF=$1;

if [ "" = "${CONF}" ]
then
    cat <<EOF

    usage:
       sudo $0 supervisor.conf.devel

       sets up environment for running drush-queues.sh from supervisor
EOF

    exit;
fi

apt-get install -qy supervisor;
cp ${PWD}/${CONF} /etc/supervisor/conf.d/drush-queues.conf;
ln -s /usr/local/bin/drush-queues.sh ${PWD}/drush-queues.sh;
service supervisor restart;