SRCREV = "${AUTOREV}"
CAMNAME = "oscam-trunk"
SUMMARY_${PN} = "OSCam-trunk ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest trunk"

PR = "r2"

RPROVIDES_${PN} += "enigma2-plugin-softcams-oscam-atv"
RREPLACES_${PN} += "enigma2-plugin-softcams-oscam-atv"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-oscam-atv"

