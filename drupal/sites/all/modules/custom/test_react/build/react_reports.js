/**
 * @file
 * Main JS file for react functionality.
 *
 */

(function ($) {

  Drupal.behaviors.react_report_blocks = {
    attach: function (context) {

      // A div with some text in it
      var ReportBox = React.createClass({displayName: "ReportBox",

      loadReportssFromServer: function() {
        $.ajax({
          url: this.props.url,
          dataType: 'json',
          success: function(data) {
            this.setState({data: data});
          }.bind(this),
          error: function(xhr, status, err) {
            console.error(this.props.url, status, err.toString());
          }.bind(this)
        });
      },

      getInitialState: function() {
        return {data: []};
      },

      componentDidMount: function() {
        this.loadReportssFromServer();
        //setInterval(this.loadReportssFromServer, this.props.pollInterval);
      },

      render: function() {
          return (
            React.createElement("div", {className: "reportBox"}, 
              React.createElement("h3", null, React.createElement("b", null, "Listing CD reports!")), 
              React.createElement(ReportList, {data: this.state.data})
            )
          );
        }
      });

      var ReportList = React.createClass({displayName: "ReportList",
        render: function() {
          var reportsNodes = this.props.data.map(function (report) {
            console.log(report);
            return (
              React.createElement(Report, {report_thumbnai: report.nid, title: report.node_title}, 
                report.node_title
              )
            );
          });
          return (
            React.createElement("div", {className: "reportList"}, 
              reportsNodes
            )
          );
        }
      });

      var Report = React.createClass({displayName: "Report",
        render: function() {
          return (
            React.createElement("div", {className: "report"}, 
              React.createElement("h2", {className: "reportAuthor"}, 
                React.createElement("span", {dangerouslySetInnerHTML: {__html: this.props.title}})
              ), 

              React.createElement("div", {dangerouslySetInnerHTML: {__html: this.props.report_thumbnai}})
            )
          );
        }
      });

      // Render our reactComponent
      React.render(
        React.createElement(ReportBox, {url: "/api/v1/views/checkdesk_reports", pollInterval: 2000}),
        document.getElementById('react-reports')
      );

    }
  }

})(jQuery);