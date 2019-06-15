MAINTAINER = "smod"
SUMMARY_${PN} = "OSCam-smod ${PKGV}"
DESCRIPTION_${PN} = "Combining the benefits of\n \
- latest trunk\n \
- modern interface\n \
- emu support \
"

SRC_URI="git://github.com/oe-alliance/oscam-smod.git;protocol=git"

CAMNAME = "oscam-smod"

EXTRA_OECMAKE += "\
	-DHAVE_PCSC=0 \
"

require oscam-common.inc

inherit gitpkgv

SRCREV = "${AUTOREV}"

SMODSVN := ""

PV = "1.20+git${SRCPV}"
PKGV = "1.20+git${GITPKGV}"

S = "${WORKDIR}/git"
F = "${WORKDIR}/git/files"

RPROVIDES_${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"
RREPLACES_${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"
RCONFLICTS_${PN} += "enigma2-plugin-softcams-oscam-ymod enigma2-plugin-softcams-oscam-atv-ymod enigma2-plugin-softcams-oscam-ymod-openatv"


python do_get_smodsvn () {
    src = d.getVar('S')
    f = open(src + "/.trunk-svn", "r")
    d.setVar('SMODSVN',f.readline())
}

do_configure_prepend() {
	cp ${F}/SoftCam.Key ${S}/SoftCam.Key
	perl -i -pe 's:Schimmelreiter:oe-alliance:g' ${S}/webif/status/status.html
}

do_compile_prepend() {
	# Shitquake fucks up git revision detection, patch it in
	export GITREV=$(echo ${GITPKGV}) ; sed -i s#GIT_VERSION\ \"test\"#GIT_VERSION\ \"${GITREV}\"# ${S}/globals.h

	# As we build for a STB, set default for dvbapi to 1 and don't hide idle clients
	perl -i -pe 's:(OFS\(dvbapi_enabled\)[ \t]*?,[ \t]*?)0\),:${1}1\),:g' ${S}/oscam-config-global.c
	perl -i -pe 's:(OFS\(dvbapi_read_sdt\)[ \t]*?,[ \t]*?)0\),:${1}1\),:g' ${S}/oscam-config-global.c
	perl -i -pe 's:(OFS\(http_hide_idle_clients\)[ \t]*?,[ \t]*?)1\),:${1}0\),:g' ${S}/oscam-config-global.c

	LDFLAGS="${LDFLAGS} -Wl,--format=binary -Wl,SoftCam.Key -Wl,--format=default"
}

#addtask get_smodsvn after do_unpack before do_patch
