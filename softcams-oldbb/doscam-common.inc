SUMMARY_${PN} = "doscam ${PV} softcam"

FILESEXTRAPATHS_prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-doscam:"

RDEPENDS_${PN} = "libusb1"
RDEPENDS_${PN}_aarch64 = ""

CONFFILES_${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

do_configure_prepend () {
        cp ${WORKDIR}/init.doscam ${S}/init.${CAMNAME}
}
