#!/bin/bash

# 2014-03-13
# Benjamin Foote
# bfoote@meedan.net

# setup a new user and database for checkdesk

genpasswd() {
    tr -dc A-Za-z0-9 < /dev/urandom | head -c 32 | xargs
}

usage() {

    cat <<EOF
\nInstall a new Checkdesk Database
\n
\nusage:
\n\t${0} instance_name [dbhost] [redishost]
\n
EOF

}

INSTANCE=$1;
if [ "$INSTANCE" = "" ];
then
    echo -e $(usage);
    exit;
fi

DBHOST=$2;
if [ "$DBHOST" = "" ];
then
    DBHOST="localhost";
fi

REDISHOST=$3
if [ "$REDISHOST" = "" ];
then
    REDISHOST="localhost";
fi

PASSWORD=$(genpasswd);

echo -e "setting up checkdesk instance for ${1}";
echo -e "\nnew password for DB user ${1} is:";
echo -e "\t\033[1m${PASSWORD}\033[0m";
echo -e "\nsanity check these:"

for TEMPLATE in $(ls *.template)
do
    FILE=$(basename $TEMPLATE .template);

    cp $TEMPLATE $FILE;
    echo -e "\t$FILE";
    sed -i "s/ddINSTANCEdd/$INSTANCE/g" $FILE;
    sed -i "s/ddPASSWORDdd/$PASSWORD/g" $FILE;
    sed -i "s/ddDBHOSTdd/$DBHOST/g" $FILE;
    sed -i "s/ddREDISHOSTdd/$REDISHOST/g" $FILE;

done


echo -e "
and then run these:
\tmysql -u root -h ${DBHOST} -p < create_database_and_user.sql
\tmysql -u $INSTANCE -h ${DBHOST} -p$PASSWORD $INSTANCE < checkdesk.sql

"






