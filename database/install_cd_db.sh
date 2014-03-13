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
\n\t${0} instance_name [dbhost]
\n
EOF

}

if [ "$1" = "" ];
then
    echo -e $(usage);
    exit;
fi

INSTANCE=$1;
DBHOST=$2;
if [ "$DBHOST" = "" ];
then
    DBHOST="localhost";
fi

PASSWORD=$(genpasswd);

echo "creating checkdesk instance for ${1}";
echo "new password for DB user ${1} is:";
echo -e "\033[1m${PASSWORD}\033[0m";

cp create_database_and_user.sql.template create_database_and_user.sql;

sed -i "s/ddINSTANCEdd/$INSTANCE/g" create_database_and_user.sql;
sed -i "s/ddPASSWORDdd/$PASSWORD/g" create_database_and_user.sql;

echo "mysql -u root -h ${DBHOST} -p < create_database_and_user.sql";

echo "mysql -u $INSTANCE -h ${DBHOST} -p$PASSWORD $INSTANCE < checkdesk.sql";






