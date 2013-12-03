var url_api = "http://qrbus.ru/tizen/";

function get_arriving(stop_id) {
}	//~ get_arriving

function go_stop(sid, sname)
{
	stop_id = sid;
	stop_name = sname;
	gHistStops.push(sid);
	gHistNames.push(sname);
	if (gHistNames.length > histlen)
	{
		gHistNames.pop();
		gHistStops.pop();
	}
    localStorage.setItem("histnames", JSON.stringify(gHistNames));
    localStorage.setItem("histstops", JSON.stringify(gHistStops));
}

function fill_arriving(stop_id) {
	url = url_api + "arriving.php";
	$("#stopname").text(stop_name);
	console.log("Routes: Fetching " + url + " for " + stop_id);
	//~ ARRAY OF IDs AND TYPES
	type = "Автобус";
	$.get( url, { stop_id: stop_id } ).done(function( data ) {
		var info = jQuery.parseJSON( data ).arriving;
		if (info != undefined)
		{
			$( "#buslist").empty();
			routes = [];
			times = [];
			for (var i = 0; i < info.length; i++)
			{
				si = info[i];
				if (routes.indexOf(si.routeNumber) == -1)
				{
					routes.push(si.routeNumber);
					times.push([]);
				}
				times[routes.indexOf(si.routeNumber)].push(si.timeToArrive);
			}
			if (routes.length > 0)
				for (var i = 0; i < routes.length; i++)
				{
					tta = "";
					for (var j = 0; j < times[i].length; j++)
						tta += times[i][j] + ", ";
					if (tta.length > 2)
						tta = tta.substring(0, tta.length - 2);
					$( "#buslist").listview( 'addItem', "<li class=\"ui-li-has-multiline\"><a href=\"#\">"+type+" №"+routes[i]+"<span class=\"ui-li-text-sub\">"+tta+" мин</span></a></li>", $("#buslist li").length );
				}
			  else{
					$( "#buslist").empty();
					$( "#buslist").listview( 'addItem', "<li class=\"ui-li-has-multiline\"><a href=\"#\" class=\"stop\">К сожалению, не удалось получить список.<span class=\"ui-li-text-sub\">Возможно, это ошибка транспорта, либо транспорт уже не ходит ночью.</span></a></li>", 1 );
				  }
				
		}
	}).fail(function() {
	    alert( "Error querying QRBus API, please check Internet connection!" );
	});
}	//~ fill_arriving

function qr_scan() {
    startMessagePort();
    
	tizen.application.launch(gServiceAppId);
	//~ launchServiceApp();
	go_stop(1942, "Пражская ул., уг. пр. Славы");
	setTimeout(function() {
		$.mobile.changePage( "#two" );
		
	}, 3000);
}	//~ qr_scan

function showHist(){
	$( "#histlist").empty();
	for (var i = 0; i < gHistStops.length; i++)
	{
		si = gHistStops[i];
		type = "";
		stopname = gHistNames[i].replace(/"/g, '');
       	$( "#histlist").listview( 'addItem', "<li class=\"ui-li-has-multiline\"><a href=\"#two\" class=\"stop\" onclick=\"go_stop("+si+', \''+stopname+'\');">'+type+" "+stopname+"<span class=\"ui-li-text-sub\">Сегодня, &lt;1км</span></a></li>", $("#histlist li").length );
	}
	if (gHistStops.length < 1)
		$( "#histlist").listview( 'addItem', "<li><a href=\"#\" class=\"stop\">История пуста!</a>", 1 );

}	//~ showHist