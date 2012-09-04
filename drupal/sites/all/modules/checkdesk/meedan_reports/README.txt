
Steps to add new reports to meedan reports

1- Implement hook_meedan_reports_info().
       = this hook should return associative arrays(key will represent report type and value will be used as title)

2- Implements of hook_meedan_reports_query($type, $year).
      = $type is one of keys that returned on hook_reports_info() hook.
      = $year is a year value (used if user filter by year)
      = return an associative array with title and query keys
      = $query must be a query object of db_select

3- clear menu cache

4- go to admin/meedan/reports to see new reports
