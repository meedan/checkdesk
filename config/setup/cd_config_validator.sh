#!/bin/bash

# Benjamin Foote
# March 2014
# used to validate the checkdesk production environment

ROOT=/var/www/checkdesk.prod
INSTANCE=$1
DOMAIN=$2

# sites
SITES=$ROOT/current/drupal/sites/$DOMAIN;
SITESETTINGS="${SITES}/settings.php";
SITESFILES="${SITES}/files";                    # links to shared
SITESSETLOCAL="${SITES}/settings.local.php";    # links to shared

# shared
SHARED=$ROOT/shared/$DOMAIN;
SHAREDFILES="${SHARED}/files";                  # links to nfs
SHAREDSETLOCAL="${SHARED}/settings.local.php";  # should link to nfs, but doesn't currently

# nfs
NFS=$ROOT/nfs/$DOMAIN;
NFSFILES="${NFS}/files";                  
NFSSETLOCAL="${NFS}/settings.local.php";  

FILES=($SITES $SITESETTINGS $SHARED $NFS $NFSFILES $NFSSETLOCAL);

LINKS=($SITESFILES $SITESSETLOCAL $SHAREDFILES);

LINKFROM=($SITESFILES $SITESSETLOCAL $SHAREDFILES)
LINKTO=($SHAREDFILES $SHAREDSETLOCAL $NFSFILES)

SETTINGS=($SITESETTINGS $SITESSETLOCAL);

echo -e "\nvalidating ${INSTANCE} for ${DOMAIN}";

# validate file existence
echo -e "\nconfirming files exist";
for F in "${FILES[@]}"
do
    if [ ! -e $F ];
    then
	echo "not found: ${F}"
    else
	echo -e "$(stat -c %a ${F}) $(stat -c %U ${F}):$(stat -c %G ${F})\t${F}";
    fi
done

# validate symlinks
echo -e "\nvalidate symlinks are links";
for LINK in "${LINKS[@]}"
do
    if [ ! -L $LINK ];
    then
	echo "not link: ${LINK}"
    else
	if [ ! -e $LINK ];
	then
	    echo "link doesn't point!: ${LINK}";
	fi
	echo -e "$(stat -c %a ${LINK}) $(stat -c %U ${LINK}):$(stat -c %G ${LINK})\t${LINK}";
    fi
done

echo -e "\nvalidate symlinks point to the correct spot";
I=0
while [ "$I" -lt "${#LINKFROM[@]}" ]
do  
    TO=$(readlink ${LINKFROM[$I]});
    if [ $TO != ${LINKTO[$I]} ]
    then
	echo -e "\tBAD LINK\n\t${LINKFROM[$I]}\n\t$TO\n\t${LINKTO[$I]}";
    else
	echo -e "\t${LINKFROM[$I]} --> $TO";
    fi
    I+=1;
done

# validate settings.local.php
for S in "${SETTINGS[@]}"
do
    echo -e "\ngrep for settings in $S";
    grep $DOMAIN $S;
    grep $INSTANCE $S;
done


