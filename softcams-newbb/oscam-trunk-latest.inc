SUMMARY_${PN} = "OSCam-trunk ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- latest trunk"

RPROVIDES:${PN} += "enigma2-plugin-softcams-oscam-atv"
RREPLACES:${PN} += "enigma2-plugin-softcams-oscam-atv"
RCONFLICTS:${PN} += "enigma2-plugin-softcams-oscam-atv"
