SRCREV = "11518"
CAMNAME = "oscam-stable"
SUMMARY_${PN} = "OSCam-stable ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- build from a known stable trunk revision\n \
- includes patch for Sogno/Venton boxes"

SRC_URI += " \
            file://sogno_unibox_dvbapi-11518_boxtype_sogno_version.patch \
"

PR = "r2"
