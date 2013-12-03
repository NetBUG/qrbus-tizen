var app = tizen.application.getCurrentApplication();
var gServiceAppId = "2lkhtWF7d2.QRService";
var gLocalMessagePortName = "QR_PORT";

var gLocalMessagePort;
var gRemoteMessagePort;

var gLocalMessagePortWatchId;

var isStarting = false;
var backEventListener = null;

var stop_id = null;
var stop_name = null;

var unregister = function() {
	if(gRemoteMessagePort)
		gRemoteMessagePort = null;
	if(gLocalMessagePort) {
		gLocalMessagePort.removeMessagePortListener(gLocalMessagePortWatchId);
		gLocalMessagePort = null;
	}

	if ( backEventListener !== null ) {
        document.removeEventListener( 'tizenhwkey', backEventListener );
        backEventListener = null;
        window.tizen.application.getCurrentApplication().exit();
    }
}

//Initialize function
var init = function () {
    // register once
    if ( backEventListener !== null ) {
        return;
    }
    
    // TODO:: Do your initialization job
    console.log("init() called");
    
    var backEvent = function(e) {
        if ( e.keyName == "back" ) {
            try {
                if ( $.mobile.urlHistory.activeIndex <= 0 ) {
                    // if first page, terminate app
                    unregister();
                } else {
                    // move previous page
                    $.mobile.urlHistory.activeIndex -= 1;
                    $.mobile.urlHistory.clearForward();
                    window.history.back();
                }
            } catch( ex ) {
                unregister();
            }
        }
    }
    
    // add eventListener for tizenhwkey (Back Button)
    document.addEventListener( 'tizenhwkey', backEvent );
    backEventListener = backEvent;
    
    startMessagePort();
    
    $(".stop").click(function(event) {
    	stop_id = $(event.target).data("id");
    	stop_name = $(event.target).text();
    });
	$( "#two" ).on( "pageshow" , function() {
		//console.log("Changing content of "+$( "#buslist").text());
		$( "#buslist").empty();
		$( "#buslist").listview( 'addItem', "<li><p>Пожалуйста, подождите...</p><p>Идёт загрузка данных</p></li>", $("#buslist li").length );
		fill_arriving(stop_id);
	});
    $("#one").on("pageshow", getPosition);
};	//~ init

function getPosition()
{
	  if (navigator.geolocation)
	    {
	    navigator.geolocation.getCurrentPosition(showPosition);
	    }
	  else{
		$( "#stoplist").empty();
		$( "#stoplist").listview( 'addItem', "<li><a href=\"#\" class=\"stop\">К сожалению, Ваш телефон не поддерживает определение местоположения.</a>", 1 );
		$( "#stoplist").listview( 'addItem', "<li><a href=\"#\" class=\"stop\">Проверьте настройки геолокации (GPS).</a>", 2 );
	  }
}	//~ getPosition

function showPosition(position)
{
	//alert("Latitude: " + position.coords.latitude + "<br>Longitude: " + position.coords.longitude);
	url = url_api + "stopsearch.php";
	$.get( url, { lat: position.coords.latitude, lon: position.coords.longitude } ).done(function( data ) {
		console.log("Stops: Got reply: " + data);
		$( "#stoplist").empty();
		var info = jQuery.parseJSON( data );
		for (var i = 0; i < Math.min(info.length, 7); i++)
		{
			si = info[i];
			type = "";
			switch(si.transport_type) {
			case "trolley": type = ""; break;
			case "tram": type = ""; break;
			case "bus": type = ""; break;
			}
			//~ <span class=\"ui-li-text-sub\">"+info[i].timeToArrive+" мин</span> //~ add for some routes coming
			stopname = si.stop_name.replace(/"/g, '');
           	$( "#stoplist").listview( 'addItem', "<li class=\"ui-li-has-multiline\"><a href=\"#two\" class=\"stop\" onclick=\"stop_id="+si.stop_code+'; stop_name=\''+stopname+'\'">'+type+" "+stopname+"<span class=\"ui-li-text-sub\">"+(Math.round(info[i].distance * 100) * 10)+"м</span></a></li>", $("#buslist li").length );
			//$( "#stoplist").listview( 'addItem', "<div data-role=\"collapsible\" data-inset=\"false\"><li class=\"ui-li-dialogue\"><a href=\"#two\" class=\"stop\" onclick=\"stop_id="+si.stop_code+'; stop_name=\''+si.stop_name+'\'">'+type+" "+si.stop_name+"</a></li><li class=\"ui-li-dialogue\">Uncompressed!</li></div>", $("#buslist li").length );
		}
		if (info.length < 1)
			$( "#stoplist").listview( 'addItem', "<li><a href=\"#\" class=\"stop\">К сожалению, для Вашего местоположения остановки не найдены</a>", 1 );
	}).fail(function() {
	    alert( "Error querying QRBus API, please check Internet connection!" );
	});
    $(".stop").click(function(event) {
    	console.log("urra");
    	alert($(event.target).data("id"));
    	stop_name = $(event.target).text();
    });

}	//~ showPosition

$(document).bind( 'pageinit', init );
$(document).unload( unregister );

function startMessagePort() {
	try {
		gLocalMessagePort = tizen.messageport.requestLocalMessagePort(gLocalMessagePortName);
		gLocalMessagePortWatchId = gLocalMessagePort.addMessagePortListener( function(data, remote) {
			onReceive(data, remote);
		});
	} catch (e) {
		writeToScreen(e.name);
	}
}

function onReceive(data, remote) {
	var message;

	for(var i in data) {
		if(data[i].key == "server")
			message = data[i].value;
	}
	
	console.log("Received : " + message);
	//~ message = "http://qrs.su/ll";
	$.get( url, { stop_id: stop_id } ).done(function( data, status, xhr ) {
		alert(XMLHttpRequest.getResponseHeader('some_header'));	
	}).fail(function(xhr) {
		alert(XMLHttpRequest.getResponseHeader('some_header'));
	    alert( "Error querying QRBus API, please check Internet connection!" );
	});
	stop_id = message;
}

function writeToScreen(message) {
	var today = new Date(),
		time = today.getFullYear() + "-" + (today.getMonth() + 1) + "-" + today.getDate() + " "
				+ today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds(),
		str = '<li class="ui-li-has-multiline ui-li-text-ellipsis">'
				+ message
				+ '<span class="ui-li-text-sub">'
				+ time
				+ '</span></li>';

	$("#logs").append(str).listview("refresh");
}

function start() {
	try {
		tizen.application.getAppsContext(onGetAppsContextSuccess, onGetAppsContextError);
	} catch (exc) {
		writeToScreen("Get AppContext Error");
	}
}

function onGetAppsContextSuccess(contexts) {
	for (var i = 0; i < contexts.length; i++) {
		var appInfo = tizen.application.getAppInfo(contexts[i].appId);
		if(appInfo.id == gServiceAppId){
			console.log("Running Service App found");
			break;
		}
	}
	if (i >= contexts.length) {
		console.log("Running Service App not found. Trying to launch it");
		launchServiceApp();
		//listInstalledApps();
	}else{
		startMessagePort();
	}
}

function onGetAppsContextError(err) {
	console.log("getAppsContext exc");
}

function listInstalledApps() {
	try {
		tizen.application.getAppsInfo(getAppsInfoSuccessCB, getAppsInfoErrorCB);
	} catch (exc) {
		writeToScreen("Get Installed App Info Error");
	}
}

function getAppsInfoSuccessCB(apps) {
	for (var i = 0; i < apps.length; i++) {
		if(apps[i].id == gServiceAppId){
			console.log("Found installed Service App")
			break;
		}
	}
	if(i >= apps.length){
		writeToScreen("Service App not installed");
		isStarting = false;
		return;
	}
	launchServiceApp();
}

function getAppsInfoErrorCB(err) {
	console.log("getAppsInfo failed");
	isStarting = false;
}

function launchServiceApp() {
	function onSuccess() {
		console.log("Service App launched successfully!");
		console.log("Restart...");
		start();
	}

	function onError(err) {
		console.log("Service Applaunch failed");
		isStarting = false;
		alert("Failed to launch MediaService!");
	}

	try {
		console.log("Launching [" + gServiceAppId + "] ...");
		tizen.application.launch(gServiceAppId, onSuccess, onError);
	} catch (exc) {
		alert("launch exc:" + exc.message);
	}
}
