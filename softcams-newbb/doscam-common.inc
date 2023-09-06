SUMMARY:${PN} = "doscam ${PV} softcam"

FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-doscam:"

RDEPENDS:${PN} = "libusb1"
RDEPENDS:${PN}:aarch64 = "libusb1"

CONFFILES:${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

do_configure:prepend () {
        cp ${WORKDIR}/init.doscam ${S}/init.${CAMNAME}
}
