S/W Version Information
Model: Ref.Device-PQ
Tizen-Version: 2.2.1
Build-Number: Tizen_Ref.Device-PQ_20131107.2323
Build-Date: 2013.11.07 23:23:19

Crash Information
Process Name: QRDemo
PID: 22957
Date: 2013-11-30 10:32:26(GMT+0400)
Executable File Path: /opt/apps/vd84JCg9vN/bin/QRDemo
This process is multi-thread process
pid=22957 tid=22957
Signal: 11
      (SIGSEGV)
      si_code: -6
      signal sent by tkill (sent by pid 22957, uid 5000)

Register Information
r0   = 0x00000038, r1   = 0x00144490
r2   = 0x00144490, r3   = 0x0016f76e
r4   = 0x00000038, r5   = 0x00144490
r6   = 0x000e4358, r7   = 0xfff21d0c
r8   = 0xbebc9028, r9   = 0xffff73d0
r10  = 0xfff2289c, fp   = 0xbebc8c58
ip   = 0xb430d1c5, sp   = 0xbebc8c20
lr   = 0xb26ab868, pc   = 0xb430d1cc
cpsr = 0x60000030

Memory Information
MemTotal:   797320 KB
MemFree:     53604 KB
Buffers:     40448 KB
Cached:     289860 KB
VmPeak:     122272 KB
VmSize:     122268 KB
VmLck:           0 KB
VmHWM:       22512 KB
VmRSS:       22512 KB
VmData:       8640 KB
VmStk:         136 KB
VmExe:          32 KB
VmLib:       79000 KB
VmPTE:         102 KB
VmSwap:          0 KB

Maps Information
00008000 00010000 r-xp /usr/bin/launchpad_preloading_preinitializing_daemon
00018000 000dc000 rw-p [heap]
000dc000 0016a000 rw-p [heap]
afd76000 afd82000 r-xp /usr/lib/libtzsvc.so.0.0.1
afd8f000 afd91000 r-xp /usr/lib/libemail-network.so.1.1.0
afd99000 afe43000 r-xp /usr/lib/libuw-imap-toolkit.so.0.0.0
afe51000 afe55000 r-xp /usr/lib/libss-client.so.1.0.0
afe5d000 afe62000 r-xp /usr/lib/libmmutil_jpeg.so.0.0.0
afe6b000 afe85000 r-xp /usr/lib/libnfc.so.1.0.0
afe8d000 afe9e000 r-xp /usr/lib/libnfc-common-lib.so.1.0.0
afea7000 afecd000 r-xp /usr/lib/libbluetooth-api.so.1.0.0
afed6000 afefc000 r-xp /usr/lib/libzmq.so.3.0.0
aff06000 aff0f000 r-xp /usr/lib/libpims-ipc.so.0.0.30
aff17000 aff1c000 r-xp /usr/lib/libmemenv.so.1.1.0
aff24000 aff62000 r-xp /usr/lib/libleveldb.so.1.1.0
aff6b000 aff73000 r-xp /usr/lib/libgstfft-0.10.so.0.25.0
aff7b000 affa5000 r-xp /usr/lib/libgstaudio-0.10.so.0.25.0
affae000 affbd000 r-xp /usr/lib/libgstvideo-0.10.so.0.25.0
affc5000 affdd000 r-xp /usr/lib/libgstpbutils-0.10.so.0.25.0
affdf000 b0004000 r-xp /usr/lib/libxslt.so.1.1.16
b000d000 b0011000 r-xp /usr/lib/libeukit.so.1.7.99
b0019000 b0021000 r-xp /usr/lib/libui-gadget-1.so.0.1.0
b0029000 b0032000 r-xp /usr/lib/libmsg_vobject.so
b003b000 b0045000 r-xp /usr/lib/libdrm-client.so.0.0.1
b004d000 b0066000 r-xp /usr/lib/libmsg_plugin_manager.so
b006f000 b00a8000 r-xp /usr/lib/libmsg_framework_handler.so
b00b1000 b00e5000 r-xp /usr/lib/libmsg_transaction_proxy.so
b00ee000 b012e000 r-xp /usr/lib/libmsg_utils.so
b012f000 b013e000 r-xp /usr/lib/libemail-common-use.so.1.1.0
b0147000 b01c2000 r-xp /usr/lib/libemail-core.so.1.1.0
b01d2000 b021b000 r-xp /usr/lib/libemail-storage.so.1.1.0
b0224000 b0231000 r-xp /usr/lib/libemail-ipc.so.1.1.0
b0239000 b0263000 r-xp /usr/lib/libSLP-location.so.0.0.0
b026c000 b0275000 r-xp /usr/lib/libdownload-provider-interface.so.1.1.6
b027d000 b0284000 r-xp /usr/lib/libmedia-utils.so.0.0.0
b028c000 b028e000 r-xp /usr/lib/libmedia-hash.so.1.0.0
b0296000 b02af000 r-xp /usr/lib/libmedia-thumbnail.so.1.0.0
b02b7000 b02b9000 r-xp /usr/lib/libmedia-svc-hash.so.1.0.0
b02c1000 b02d9000 r-xp /usr/lib/libmedia-service.so.1.0.0
b02e1000 b02f5000 r-xp /usr/lib/libnetwork.so.0.0.0
b02fe000 b0309000 r-xp /usr/lib/libstt.so
b0311000 b0317000 r-xp /usr/lib/libbadge.so.0.0.1
b031f000 b0325000 r-xp /usr/lib/libcapi-appfw-app-manager.so.0.1.0
b032d000 b0333000 r-xp /usr/lib/libshortcut.so.0.0.1
b033c000 b033f000 r-xp /usr/lib/libminicontrol-provider.so.0.0.1
b0347000 b0352000 r-xp /usr/lib/liblivebox-service.so.0.0.1
b035a000 b036f000 r-xp /usr/lib/liblivebox-viewer.so.0.0.1
b0377000 b037b000 r-xp /usr/lib/libcapi-appfw-package-manager.so.0.0.30
b0383000 b05a0000 r-xp /usr/lib/libface-engine-plugin.so
b05fe000 b0604000 r-xp /usr/lib/libcapi-network-nfc.so.0.0.11
b060d000 b0624000 r-xp /usr/lib/libcapi-network-bluetooth.so.0.1.40
b062c000 b0634000 r-xp /usr/lib/libcapi-network-wifi.so.0.1.2_24
b063c000 b0655000 r-xp /usr/lib/libaccounts-svc.so.0.2.66
b065d000 b06cf000 r-xp /usr/lib/libcontacts-service2.so.0.9.114.7
b06ee000 b0731000 r-xp /usr/lib/libcalendar-service2.so.0.1.44
b073b000 b0743000 r-xp /usr/lib/libcapi-web-favorites.so
b0744000 b1946000 r-xp /usr/lib/libewebkit2.so.0.11.113
b1a2b000 b1a33000 r-xp /usr/lib/libpush.so.0.2.12
b1a3b000 b1a56000 r-xp /usr/lib/libmsg_mapi.so.0.1.0
b1a5f000 b1a77000 r-xp /usr/lib/libemail-api.so.1.1.0
b1a7f000 b1a88000 r-xp /usr/lib/libcapi-system-sensor.so.0.1.17
b1a91000 b1a94000 r-xp /usr/lib/libcapi-telephony-sim.so.0.1.7
b1a9c000 b1a9f000 r-xp /usr/lib/libcapi-telephony-network-info.so.0.1.0
b1aa8000 b1ab3000 r-xp /usr/lib/libcapi-location-manager.so.0.1.11
b1abb000 b1abf000 r-xp /usr/lib/libcapi-web-url-download.so.0.1.0
b1ac7000 b1ae8000 r-xp /usr/lib/libcapi-content-media-content.so.0.2.59
b1af0000 b1af2000 r-xp /usr/lib/libcamsrcjpegenc.so.0.0.0
b1afa000 b1b0e000 r-xp /usr/lib/libwifi-direct.so.0.0
b1b16000 b1b1e000 r-xp /usr/lib/libcapi-network-tethering.so.0.1.0
b1b1f000 b1b28000 r-xp /usr/lib/libcapi-network-connection.so.0.1.3_18
b1b30000 b1b64000 r-xp /usr/lib/libopenal.so.1.13.0
b1b6d000 b1b70000 r-xp /usr/lib/libalut.so.0.1.0
b1b7a000 b1b7f000 r-xp /usr/lib/osp/libosp-speech-stt.so.1.2.2.0
b1b87000 b1ba5000 r-xp /usr/lib/osp/libosp-shell-core.so.1.2.2.1
b1bae000 b1c1f000 r-xp /usr/lib/osp/libosp-shell.so.1.2.2.1
b1c31000 b1c37000 r-xp /usr/lib/osp/libosp-speech-tts.so.1.2.2.0
b1c3f000 b1c62000 r-xp /usr/lib/osp/libosp-face.so.1.2.2.0
b1c6c000 b1cca000 r-xp /usr/lib/osp/libosp-nfc.so.1.2.2.0
b1cd6000 b1d31000 r-xp /usr/lib/osp/libosp-bluetooth.so.1.2.2.0
b1d3d000 b1db0000 r-xp /usr/lib/osp/libosp-wifi.so.1.2.2.0
b1dbc000 b1e7d000 r-xp /usr/lib/osp/libosp-social.so.1.2.2.0
b1e87000 b1efc000 r-xp /usr/lib/osp/libosp-web.so.1.2.2.0
b1f0a000 b1f57000 r-xp /usr/lib/osp/libosp-messaging.so.1.2.2.0
b1f61000 b1f7e000 r-xp /usr/lib/osp/libosp-uix.so.1.2.2.0
b1f88000 b1fa7000 r-xp /usr/lib/osp/libosp-telephony.so.1.2.2.0
b1fb0000 b1fc9000 r-xp /usr/lib/osp/libosp-locations.so.1.2.2.3
b1fd2000 b202f000 r-xp /usr/lib/osp/libosp-content.so.1.2.2.0
b2038000 b204a000 r-xp /usr/lib/osp/libosp-ime.so.1.2.2.0
b2053000 b206d000 r-xp /usr/lib/osp/libosp-json.so.1.2.2.0
b2077000 b2089000 r-xp /usr/lib/libmmfile_utils.so.0.0.0
b2091000 b2096000 r-xp /usr/lib/libmmffile.so.0.0.0
b209e000 b2102000 r-xp /usr/lib/libmmfcamcorder.so.0.0.0
b210f000 b21d4000 r-xp /usr/lib/osp/libosp-net.so.1.2.2.0
b21e2000 b2405000 r-xp /usr/lib/osp/libarengine.so
b2481000 b2486000 r-xp /usr/lib/libcapi-media-metadata-extractor.so
b248e000 b2493000 r-xp /usr/lib/libcapi-media-recorder.so.0.1.3
b249b000 b24a6000 r-xp /usr/lib/libcapi-media-camera.so.0.1.4
b24ae000 b24b1000 r-xp /usr/lib/libcapi-media-sound-manager.so.0.1.1
b24b9000 b24c7000 r-xp /usr/lib/libcapi-media-player.so.0.1.1
b24cf000 b24f0000 r-xp /usr/lib/libopencore-amrnb.so.0.0.2
b24f9000 b24fd000 r-xp /usr/lib/libogg.so.0.7.1
b2505000 b2527000 r-xp /usr/lib/libvorbis.so.0.4.3
b252f000 b2533000 r-xp /usr/lib/libcapi-media-audio-io.so.0.2.0
b253b000 b2559000 r-xp /usr/lib/osp/libosp-image.so.1.2.2.0
b2562000 b2580000 r-xp /usr/lib/osp/libosp-vision.so.1.2.2.0
b2589000 b2680000 r-xp /usr/lib/osp/libosp-media.so.1.2.2.0
b26a4000 b26b4000 r-xp /opt/usr/apps/vd84JCg9vN/bin/QRDemo.exe
b26bd000 b272f000 r-xp /usr/lib/libosp-env-config.so.1.2.2.1
b2737000 b2771000 r-xp /usr/lib/libpulsecommon-0.9.23.so
b277a000 b277e000 r-xp /usr/lib/libmmfsoundcommon.so.0.0.0
b2786000 b27b7000 r-xp /usr/lib/libpulse.so.0.12.4
b27bf000 b2822000 r-xp /usr/lib/libasound.so.2.0.0
b282c000 b282f000 r-xp /usr/lib/libpulse-simple.so.0.0.3
b2837000 b283b000 r-xp /usr/lib/libascenario-0.2.so.0.0.0
b2844000 b2861000 r-xp /usr/lib/libavsysaudio.so.0.0.1
b2869000 b2877000 r-xp /usr/lib/libmmfsound.so.0.1.0
b287f000 b291b000 r-xp /usr/lib/libgstreamer-0.10.so.0.30.0
b2927000 b2968000 r-xp /usr/lib/libgstbase-0.10.so.0.30.0
b2971000 b297a000 r-xp /usr/lib/libgstapp-0.10.so.0.25.0
b2982000 b298f000 r-xp /usr/lib/libgstinterfaces-0.10.so.0.25.0
b2998000 b299e000 r-xp /usr/lib/libUMP.so
b29a6000 b29a9000 r-xp /usr/lib/libmm_ta.so.0.0.0
b29b1000 b29c0000 r-xp /usr/lib/libICE.so.6.3.0
b29ca000 b29cf000 r-xp /usr/lib/libSM.so.6.0.1
b29d7000 b29d8000 r-xp /usr/lib/libmmfkeysound.so.0.0.0
b29e0000 b29e8000 r-xp /usr/lib/libmmfcommon.so.0.0.0
b29f0000 b29f8000 r-xp /usr/lib/libaudio-session-mgr.so.0.0.0
b2a03000 b2a06000 r-xp /usr/lib/libmmfsession.so.0.0.0
b2a0e000 b2a52000 r-xp /usr/lib/libmmfplayer.so.0.0.0
b2a5b000 b2a6e000 r-xp /usr/lib/libEGL_platform.so
b2a77000 b2b4e000 r-xp /usr/lib/libMali.so
b2b59000 b2b5f000 r-xp /usr/lib/libxcb-render.so.0.0.0
b2b67000 b2b68000 r-xp /usr/lib/libxcb-shm.so.0.0.0
b2b71000 b2baf000 r-xp /usr/lib/libGLESv2.so.2.0
b2bb7000 b2c02000 r-xp /usr/lib/libtiff.so.5.1.0
b2c0d000 b2c36000 r-xp /usr/lib/libturbojpeg.so
b2c4f000 b2c55000 r-xp /usr/lib/libmmutil_imgp.so.0.0.0
b2c5d000 b2c63000 r-xp /usr/lib/libgif.so.4.1.6
b2c6b000 b2c8d000 r-xp /usr/lib/libavutil.so.51.73.101
b2c9c000 b2cca000 r-xp /usr/lib/libswscale.so.2.1.101
b2cd3000 b2fca000 r-xp /usr/lib/libavcodec.so.54.59.100
b32f1000 b330a000 r-xp /usr/lib/libpng12.so.0.50.0
b3313000 b3319000 r-xp /usr/lib/libfeedback.so.0.1.4
b3321000 b332d000 r-xp /usr/lib/libtts.so
b3335000 b334c000 r-xp /usr/lib/libEGL.so.1.4
b3355000 b340c000 r-xp /usr/lib/libcairo.so.2.11200.12
b3416000 b3430000 r-xp /usr/lib/osp/libosp-image-core.so.1.2.2.0
b3439000 b3d37000 r-xp /usr/lib/osp/libosp-uifw.so.1.2.2.1
b3daa000 b3daf000 r-xp /usr/lib/libslp_devman_plugin.so
b3db8000 b3dbb000 r-xp /usr/lib/libsyspopup_caller.so.0.1.0
b3dc3000 b3dc7000 r-xp /usr/lib/libsysman.so.0.2.0
b3dcf000 b3de0000 r-xp /usr/lib/libsecurity-server-commons.so.1.0.0
b3de9000 b3deb000 r-xp /usr/lib/libsystemd-daemon.so.0.0.1
b3df3000 b3df5000 r-xp /usr/lib/libdeviced.so.0.1.0
b3dfd000 b3e13000 r-xp /usr/lib/libpkgmgr_parser.so.0.1.0
b3e1b000 b3e1d000 r-xp /usr/lib/libpkgmgr_installer_status_broadcast_server.so.0.1.0
b3e25000 b3e28000 r-xp /usr/lib/libpkgmgr_installer_client.so.0.1.0
b3e30000 b3e33000 r-xp /usr/lib/libdevice-node.so.0.1
b3e3b000 b3e3f000 r-xp /usr/lib/libheynoti.so.0.0.2
b3e47000 b3e8c000 r-xp /usr/lib/libsoup-2.4.so.1.5.0
b3e95000 b3eaa000 r-xp /usr/lib/libsecurity-server-client.so.1.0.1
b3eb3000 b3eb7000 r-xp /usr/lib/libcapi-system-info.so.0.2.0
b3ebf000 b3ec4000 r-xp /usr/lib/libcapi-system-system-settings.so.0.0.2
b3ecc000 b3ecd000 r-xp /usr/lib/libcapi-system-power.so.0.1.1
b3ed6000 b3ed9000 r-xp /usr/lib/libcapi-system-device.so.0.1.0
b3ee1000 b3ee4000 r-xp /usr/lib/libcapi-system-runtime-info.so.0.0.3
b3eed000 b3ef0000 r-xp /usr/lib/libcapi-network-serial.so.0.0.8
b3ef8000 b3ef9000 r-xp /usr/lib/libcapi-content-mime-type.so.0.0.2
b3f01000 b3f0f000 r-xp /usr/lib/libcapi-appfw-application.so.0.1.0
b3f18000 b3f3a000 r-xp /usr/lib/libSLP-tapi.so.0.0.0
b3f42000 b3f45000 r-xp /usr/lib/libuuid.so.1.3.0
b3f4e000 b3f6c000 r-xp /usr/lib/libpkgmgr-info.so.0.0.17
b3f74000 b3f8b000 r-xp /usr/lib/libpkgmgr-client.so.0.1.68
b3f94000 b3f95000 r-xp /usr/lib/libpmapi.so.1.2
b3f9d000 b3fa5000 r-xp /usr/lib/libminizip.so.1.0.0
b3fad000 b3fb8000 r-xp /usr/lib/libmessage-port.so.1.2.2.1
b3fc0000 b4098000 r-xp /usr/lib/libxml2.so.2.7.8
b40a5000 b40c3000 r-xp /usr/lib/libpcre.so.0.0.1
b40cb000 b40ce000 r-xp /usr/lib/libiniparser.so.0
b40d7000 b40db000 r-xp /usr/lib/libhaptic.so.0.1
b40e3000 b40ee000 r-xp /usr/lib/libcryptsvc.so.0.0.1
b40fb000 b4100000 r-xp /usr/lib/libdevman.so.0.1
b4109000 b410d000 r-xp /usr/lib/libchromium.so.1.0
b4115000 b411b000 r-xp /usr/lib/libappsvc.so.0.1.0
b4123000 b4124000 r-xp /usr/lib/osp/libappinfo.so.1.2.2.1
b4134000 b4136000 r-xp /opt/usr/apps/vd84JCg9vN/bin/QRDemo
b413e000 b4144000 r-xp /usr/lib/libalarm.so.0.0.0
b414d000 b415f000 r-xp /usr/lib/libprivacy-manager-client.so.0.0.5
b4167000 b4467000 r-xp /usr/lib/osp/libosp-appfw.so.1.2.2.1
b4486000 b4490000 r-xp /lib/libnss_files-2.13.so
b4499000 b44a2000 r-xp /lib/libnss_nis-2.13.so
b44ab000 b44bc000 r-xp /lib/libnsl-2.13.so
b44c7000 b44cd000 r-xp /lib/libnss_compat-2.13.so
b44d6000 b44df000 r-xp /usr/lib/libcapi-security-privilege-manager.so.0.0.3
b4807000 b4818000 r-xp /usr/lib/libcom-core.so.0.0.1
b4820000 b4822000 r-xp /usr/lib/libdri2.so.0.0.0
b482a000 b4832000 r-xp /usr/lib/libdrm.so.2.4.0
b483a000 b483e000 r-xp /usr/lib/libtbm.so.1.0.0
b4846000 b4849000 r-xp /usr/lib/libXv.so.1.0.0
b4851000 b491c000 r-xp /usr/lib/libscim-1.0.so.8.2.3
b4932000 b4942000 r-xp /usr/lib/libnotification.so.0.1.0
b494a000 b496e000 r-xp /usr/lib/ecore/immodules/libisf-imf-module.so
b4977000 b4987000 r-xp /lib/libresolv-2.13.so
b498b000 b498d000 r-xp /usr/lib/libgmodule-2.0.so.0.3200.3
b4995000 b4ae8000 r-xp /usr/lib/libcrypto.so.1.0.0
b4b06000 b4b52000 r-xp /usr/lib/libssl.so.1.0.0
b4b5e000 b4b8a000 r-xp /usr/lib/libidn.so.11.5.44
b4b93000 b4b9d000 r-xp /usr/lib/libcares.so.2.0.0
b4ba5000 b4bbc000 r-xp /lib/libexpat.so.1.5.2
b4bc6000 b4bea000 r-xp /usr/lib/libicule.so.48.1
b4bf3000 b4bfb000 r-xp /usr/lib/libsf_common.so
b4c03000 b4c9e000 r-xp /usr/lib/libstdc++.so.6.0.14
b4cb1000 b4d8e000 r-xp /usr/lib/libgio-2.0.so.0.3200.3
b4d99000 b4dbe000 r-xp /usr/lib/libexif.so.12.3.3
b4dd2000 b4ddc000 r-xp /usr/lib/libethumb.so.1.7.99
b4de4000 b4e28000 r-xp /usr/lib/libsndfile.so.1.0.25
b4e36000 b4e38000 r-xp /usr/lib/libctxdata.so.0.0.0
b4e40000 b4e4e000 r-xp /usr/lib/libremix.so.0.0.0
b4e56000 b4e57000 r-xp /usr/lib/libecore_imf_evas.so.1.7.99
b4e5f000 b4e78000 r-xp /usr/lib/liblua-5.1.so
b4e81000 b4e88000 r-xp /usr/lib/libembryo.so.1.7.99
b4e91000 b4e94000 r-xp /usr/lib/libecore_input_evas.so.1.7.99
b4e9c000 b4ed9000 r-xp /usr/lib/libcurl.so.4.3.0
b4ee3000 b4ee7000 r-xp /usr/lib/libecore_ipc.so.1.7.99
b4ef0000 b4f5a000 r-xp /usr/lib/libpixman-1.so.0.28.2
b4f67000 b4f8b000 r-xp /usr/lib/libfontconfig.so.1.5.0
b4f94000 b4ff0000 r-xp /usr/lib/libharfbuzz.so.0.907.0
b5002000 b5016000 r-xp /usr/lib/libfribidi.so.0.3.1
b501e000 b5073000 r-xp /usr/lib/libfreetype.so.6.8.1
b507e000 b50a2000 r-xp /usr/lib/libjpeg.so.8.0.2
b50ba000 b50d1000 r-xp /lib/libz.so.1.2.5
b50d9000 b50e6000 r-xp /usr/lib/libsensor.so.1.1.0
b50f1000 b50f3000 r-xp /usr/lib/libapp-checker.so.0.1.0
b50fb000 b5101000 r-xp /usr/lib/libxdgmime.so.1.1.0
b6218000 b6300000 r-xp /usr/lib/libicuuc.so.48.1
b630d000 b642d000 r-xp /usr/lib/libicui18n.so.48.1
b643b000 b643e000 r-xp /usr/lib/libSLP-db-util.so.0.1.0
b6446000 b644f000 r-xp /usr/lib/libvconf.so.0.2.45
b6457000 b6465000 r-xp /usr/lib/libail.so.0.1.0
b646d000 b6485000 r-xp /usr/lib/libdbus-glib-1.so.2.2.2
b6486000 b648b000 r-xp /usr/lib/libffi.so.5.0.10
b6493000 b6494000 r-xp /usr/lib/libgthread-2.0.so.0.3200.3
b649c000 b64a6000 r-xp /usr/lib/libXext.so.6.4.0
b64af000 b64b2000 r-xp /usr/lib/libXtst.so.6.1.0
b64ba000 b64c0000 r-xp /usr/lib/libXrender.so.1.3.0
b64c8000 b64ce000 r-xp /usr/lib/libXrandr.so.2.2.0
b64d6000 b64d7000 r-xp /usr/lib/libXinerama.so.1.0.0
b64e0000 b64e9000 r-xp /usr/lib/libXi.so.6.1.0
b64f1000 b64f4000 r-xp /usr/lib/libXfixes.so.3.1.0
b64fc000 b64fe000 r-xp /usr/lib/libXgesture.so.7.0.0
b6506000 b6508000 r-xp /usr/lib/libXcomposite.so.1.0.0
b6510000 b6511000 r-xp /usr/lib/libXdamage.so.1.1.0
b651a000 b6521000 r-xp /usr/lib/libXcursor.so.1.0.2
b6529000 b6531000 r-xp /usr/lib/libemotion.so.1.7.99
b6539000 b6554000 r-xp /usr/lib/libecore_con.so.1.7.99
b655d000 b6562000 r-xp /usr/lib/libecore_imf.so.1.7.99
b656b000 b6573000 r-xp /usr/lib/libethumb_client.so.1.7.99
b657b000 b657d000 r-xp /usr/lib/libefreet_trash.so.1.7.99
b6585000 b6589000 r-xp /usr/lib/libefreet_mime.so.1.7.99
b6592000 b65a8000 r-xp /usr/lib/libefreet.so.1.7.99
b65b2000 b65bb000 r-xp /usr/lib/libedbus.so.1.7.99
b65c3000 b65c8000 r-xp /usr/lib/libecore_fb.so.1.7.99
b65d1000 b662d000 r-xp /usr/lib/libedje.so.1.7.99
b6637000 b664e000 r-xp /usr/lib/libecore_input.so.1.7.99
b6669000 b666e000 r-xp /usr/lib/libecore_file.so.1.7.99
b6676000 b6693000 r-xp /usr/lib/libecore_evas.so.1.7.99
b669c000 b66db000 r-xp /usr/lib/libeina.so.1.7.99
b66e4000 b6793000 r-xp /usr/lib/libevas.so.1.7.99
b67b5000 b67c8000 r-xp /usr/lib/libeet.so.1.7.99
b67d1000 b683b000 r-xp /lib/libm-2.13.so
b6847000 b684e000 r-xp /usr/lib/libutilX.so.1.1.0
b6856000 b685b000 r-xp /usr/lib/libappcore-common.so.1.1
b6863000 b686e000 r-xp /usr/lib/libaul.so.0.1.0
b6877000 b68ab000 r-xp /usr/lib/libgobject-2.0.so.0.3200.3
b68b4000 b68e4000 r-xp /usr/lib/libecore_x.so.1.7.99
b68ed000 b6902000 r-xp /usr/lib/libecore.so.1.7.99
b6919000 b6a39000 r-xp /usr/lib/libelementary.so.1.7.99
b6a4c000 b6a4f000 r-xp /lib/libattr.so.1.1.0
b6a57000 b6a59000 r-xp /usr/lib/libXau.so.6.0.0
b6a61000 b6a67000 r-xp /lib/librt-2.13.so
b6a70000 b6a78000 r-xp /lib/libcrypt-2.13.so
b6aa8000 b6aab000 r-xp /lib/libcap.so.2.21
b6ab3000 b6ab5000 r-xp /usr/lib/libiri.so
b6abd000 b6ad2000 r-xp /usr/lib/libxcb.so.1.1.0
b6ada000 b6ae5000 r-xp /lib/libunwind.so.8.0.1
b6b13000 b6c30000 r-xp /lib/libc-2.13.so
b6c3e000 b6c47000 r-xp /lib/libgcc_s-4.5.3.so.1
b6c4f000 b6c52000 r-xp /usr/lib/libsmack.so.1.0.0
b6c5a000 b6c86000 r-xp /usr/lib/libdbus-1.so.3.7.2
b6c8f000 b6c93000 r-xp /usr/lib/libbundle.so.0.1.22
b6c9b000 b6c9d000 r-xp /lib/libdl-2.13.so
b6ca6000 b6d80000 r-xp /usr/lib/libglib-2.0.so.0.3200.3
b6d89000 b6df3000 r-xp /usr/lib/libsqlite3.so.0.8.6
b6dfd000 b6e0a000 r-xp /usr/lib/libprivilege-control.so.0.0.2
b6e13000 b6ef9000 r-xp /usr/lib/libX11.so.6.3.0
b6f04000 b6f18000 r-xp /lib/libpthread-2.13.so
b6f28000 b6f2c000 r-xp /usr/lib/libappcore-efl.so.1.1
b6f35000 b6f36000 r-xp /usr/lib/libdlog.so.0.0.0
b6f3e000 b6f42000 r-xp /usr/lib/libsys-assert.so
b6f4a000 b6f67000 r-xp /lib/ld-2.13.so
bebaa000 bebcb000 rwxp [stack]
End of Maps Information

Callstack Information (PID:22957)
Call Stack Count: 27
 0: Tizen::Io::RemoteMessagePort::SendMessage(Tizen::Base::Collection::IMap const*) + 0x7 (0xb430d1cc) [/usr/lib/osp/libosp-appfw.so] + 0x1a61cc
 1: QRMessagePort::SendMessage(Tizen::Base::Collection::IMap const*) + 0x8c (0xb26ab868) [/opt/apps/vd84JCg9vN/bin/QRDemo.exe] + 0x7868
 2: QrCodeRecognizer::OnAppInitialized() + 0x36c (0xb26ac9b4) [/opt/apps/vd84JCg9vN/bin/QRDemo.exe] + 0x89b4
 3: Tizen::App::_UiAppImpl::OnAppInitialized() + 0x18 (0xb3ae5d1d) [/usr/lib/osp/libosp-uifw.so] + 0x6acd1d
 4: Tizen::App::_AppImpl::OnService(service_s*, void*) + 0x208 (0xb425460d) [/usr/lib/osp/libosp-appfw.so] + 0xed60d
 5: app_appcore_reset + 0x20 (0xb3f09b75) [/usr/lib/libcapi-appfw-application.so.0] + 0x8b75
 6: __do_app + 0x2b4 (0xb6f2a0fd) [/usr/lib/libappcore-efl.so.1] + 0x20fd
 7: __aul_handler + 0x60 (0xb685798d) [/usr/lib/libappcore-common.so.1] + 0x198d
 8: app_start + 0x1c (0xb68661fd) [/usr/lib/libaul.so.0] + 0x31fd
 9: __app_start_internal + 0x8 (0xb6866b25) [/usr/lib/libaul.so.0] + 0x3b25
10: g_idle_dispatch + 0xe (0xb6cdcc53) [/usr/lib/libglib-2.0.so.0] + 0x36c53
11: g_main_context_dispatch + 0xce (0xb6cdea37) [/usr/lib/libglib-2.0.so.0] + 0x38a37
12: _ecore_glib_select + 0x3ae (0xb68fc337) [/usr/lib/libecore.so.1] + 0xf337
13: _ecore_main_select + 0x294 (0xb68f78b9) [/usr/lib/libecore.so.1] + 0xa8b9
14: _ecore_main_loop_iterate_internal + 0x2de (0xb68f82f3) [/usr/lib/libecore.so.1] + 0xb2f3
15: ecore_main_loop_begin + 0x30 (0xb68f85cd) [/usr/lib/libecore.so.1] + 0xb5cd
16: elm_run + 0x6 (0xb69c119f) [/usr/lib/libelementary.so.1] + 0xa819f
17: appcore_efl_main + 0x2d4 (0xb6f2a7d5) [/usr/lib/libappcore-efl.so.1] + 0x27d5
18: app_efl_main + 0xc6 (0xb3f09e6b) [/usr/lib/libcapi-appfw-application.so.0] + 0x8e6b
19: Tizen::App::_AppImpl::Execute(Tizen::App::_IAppImpl*) + 0xe6 (0xb42548b3) [/usr/lib/osp/libosp-appfw.so] + 0xed8b3
20: Tizen::App::UiApp::Execute(Tizen::App::UiApp* (*)(), Tizen::Base::Collection::IList const*) + 0x64 (0xb3ae5a89) [/usr/lib/osp/libosp-uifw.so] + 0x6aca89
21: OspMain + 0x13c (0xb26abc60) [/opt/apps/vd84JCg9vN/bin/QRDemo.exe] + 0x7c60
22: main + 0x194 (0xb4134f21) [/opt/apps/vd84JCg9vN/bin/QRDemo] + 0xf21
23: __launchpad_main_loop + 0xe54 (0xb259) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xb259
24: main + 0x486 (0xbcb3) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xbcb3
25: __libc_start_main + 0x114 (0xb6b286e8) [/lib/libc.so.6] + 0x156e8
26: (0xa110) [/usr/bin/launchpad_preloading_preinitializing_daemon] + 0xa110
End of Call Stack

Package Information
Package Name: vd84JCg9vN.QRDemo
Package ID : vd84JCg9vN
Version: 1.0.0
Package Type: tpk
App Name: QRDemo
App ID: vd84JCg9vN.QRDemo
Type: Application
Categories: (NULL)
