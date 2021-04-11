SRCREV = "11581"
CAMNAME = "oscam-stable"
SUMMARY_${PN} = "OSCam-stable ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- build from a known stable trunk revision\n \
- includes patch for Sogno/Venton boxes"

SRC_URI += "svn://svn.streamboard.tv/oscam;protocol=https;module=trunk;scmdata=keep;rev=${SRCREV}"

SRC_URI += " \
            file://sogno_unibox_dvbapi-11518_boxtype_sogno_version.patch \
"
