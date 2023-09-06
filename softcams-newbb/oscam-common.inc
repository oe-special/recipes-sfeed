FILESEXTRAPATHS:prepend := "${THISDIR}/../softcams/enigma2-plugin-softcams-oscam:"

CONFFILES:${PN} ?= "/etc/tuxbox/config/${CAMNAME}"

do_configure:prepend () {
	cp ${S}/../init.oscam-generic ${S}/init.${CAMNAME}
	perl -i -pe 's:DEFAULT_HTTP_PORT[ \t]*?8888:DEFAULT_HTTP_PORT 83:g' ${S}/oscam-config-global.c
}
