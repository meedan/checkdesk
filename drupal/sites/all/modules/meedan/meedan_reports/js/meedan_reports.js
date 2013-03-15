/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

function add_chart_view(params, title_chart) {
  'use strict';

  var chartData = params;
  AmCharts.ready(function () {
    var chart, categoryAxis, valueAxis,
        graph, legend, chartCursor, catAxis;

    // SERIAL CHART
    chart = new AmCharts.AmSerialChart();
    chart.pathToImages = "amcharts/samples/javascript/images/";
    chart.zoomOutButton = {
      backgroundColor: "#000000",
    backgroundAlpha: 0.15
    };
    chart.dataProvider = chartData;
    chart.marginTop = 0;
    chart.marginRight = 30;
    chart.categoryField = "Date";

    // AXES
    // Category
    categoryAxis = chart.categoryAxis;
    categoryAxis.gridAlpha = 0.07;
    categoryAxis.axisColor = "#DADADA";
    categoryAxis.startOnAxis = true;

    // Value
    valueAxis = new AmCharts.ValueAxis();
    valueAxis.stackType = "regular"; // this line makes the chart "stacked"
    valueAxis.gridAlpha = 0.07;
    valueAxis.axisColor = "#DADADA";
    valueAxis.title = title_chart + " chart";
    valueAxis.titleBold = false;
    chart.addValueAxis(valueAxis);



    // GRAPHS
    // first graph
    graph = new AmCharts.AmGraph();
    graph.type = "column";
    graph.hidden = false;
    graph.title = "Count";
    graph.valueField = "Count";
    graph.lineAlpha = 1;
    graph.fillAlphas = 0.6; // setting fillAlphas to > 0 value makes it area graph
    graph.balloonText = "[[Info]]";
    chart.addGraph(graph);


    // LEGEND
    legend = new AmCharts.AmLegend();
    legend.position = "top";
    chart.addLegend(legend);

    // CURSOR
    chartCursor = new AmCharts.ChartCursor();
    chartCursor.zoomable = true; // as the chart displayes not too many values, we disabled zooming
    chartCursor.cursorAlpha = 0;
    chart.addChartCursor(chartCursor);

    catAxis = chart.categoryAxis;
    catAxis.gridCount = chartData.length;
    catAxis.labelRotation = 90;

    // WRITE
    chart.write("chartContainer");
  });
}

(function ($) {
  'use strict';

  $("#tabs").tabs({
    collapsible: true
  });

}(jQuery));
