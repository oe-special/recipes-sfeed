SRCREV = "${AUTOREV}"
CAMNAME = "oscam-trunk"
SUMMARY_${PN} = "OSCam-trunk ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest trunk"

#PR = "r0"

RPROVIDES:${PN} += "enigma2-plugin-softcams-oscam-atv"
RREPLACES:${PN} += "enigma2-plugin-softcams-oscam-atv"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-oscam-atv"

SRC_URI += "svn://svn.streamboard.tv/oscam;protocol=https;module=trunk;scmdata=keep"
