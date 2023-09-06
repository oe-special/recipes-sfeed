CAMNAME = "oscam-stable"

SRCREV = "11715"
SRC_URI = "svn://svn.streamboard.tv/oscam;protocol=https;module=trunk;scmdata=keep;rev=${SRCREV};externals=nowarn \
           file://sogno_unibox_dvbapi-11518_boxtype_sogno_version.patch \
          "

require ${SOFTCAM_INCLUDES}/oscam-trunk-stable.inc

