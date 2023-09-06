SUMMARY_${PN} = "OSCam-icam ${PKGV}"
DESCRIPTION_${PN} = "OSCam Open Source Softcam\n \
- includes patch for Sogno/Venton boxes\n \
- includes patch for icam support"

do_install_append () {
        install -d ${D}/etc/enigma2
        install -m 0644 ${S}/../oscam-icam/userbouquet.icam-de.tv ${D}/etc/enigma2/userbouquet.icam-de.tv
        rm ${D}/etc/tuxbox/config/oscam-icam/userbouquet.icam-de.tv
}
