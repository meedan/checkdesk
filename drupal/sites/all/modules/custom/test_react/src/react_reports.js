/**
 * @file
 * Main JS file for react functionality.
 *
 */

(function ($) {

  Drupal.behaviors.react_report_blocks = {
    attach: function (context) {

      // A div with some text in it
      var ReportBox = React.createClass({

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
            <div className="reportBox">
              <h3><b>Listing CD reports!</b></h3>
              <ReportList data={this.state.data} />
            </div>
          );
        }
      });

      var ReportList = React.createClass({
        render: function() {
          var reportsNodes = this.props.data.map(function (report) {
            console.log(report);
            return (
              <Report report_thumbnai={report.nid} title={report.node_title}>
                {report.node_title}
              </Report>
            );
          });
          return (
            <div className="reportList">
              {reportsNodes}
            </div>
          );
        }
      });

      var Report = React.createClass({
        render: function() {
          return (
            <div className="report">
              <h2 className="reportAuthor">
                <span dangerouslySetInnerHTML={{__html: this.props.title}} />
              </h2>

              <div dangerouslySetInnerHTML={{__html: this.props.report_thumbnai}} />
            </div>
          );
        }
      });

      // Render our reactComponent
      React.render(
        <ReportBox url="/api/v1/views/checkdesk_reports" pollInterval={2000} />,
        document.getElementById('react-reports')
      );

    }
  }

})(jQuery);