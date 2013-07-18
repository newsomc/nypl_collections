<?php
require_once( '../lib/solr-php-client/Apache/Solr/Service.php' );

// define('SOLR_URI', variable_get('solr_host_uri', 'http://solr.farm.nypl.org'));
// define('SOLR_PORT', variable_get('solr_host_port', '8080'));
// define('SOLR_VERSION', variable_get('solr_host_version', 'solr-3.5'));

define('SOLR_URI','http://solr.farm.nypl.org');
define('SOLR_PORT','8080');
define('SOLR_VERSION','solr-3.5');
define('SOLR_USER','solradmin');
define('SOLR_PASS','WbVL2ji5fNdstUrUHDdu');

// Example query for topics
// http://solr.farm.nypl.org:8080/solr-3.5/repoapi/select/?q=*%3A*&start=0&rows=0&facet=true&facet.field=topic_mtxt_s&facet.limit=1200

function SolrSearch($query){
  $solr = new Apache_Solr_Service(SOLR_URI, SOLR_PORT, '/' . SOLR_VERSION . '/');
  $solr->setAuthenticationCredentials(SOLR_USER, SOLR_PASS);

  if (!$solr->ping()) {
    print 'Solr service not responding.';
    die();
  }

  if (get_magic_quotes_gpc() == 1) {
    $query = stripslashes($query);
  }

  try {
      $results = $solr->search($query, 0, $limit);
  }
  catch (Exception $e) {
    // in production log or email this error to an admin
    // and then show a special message to the user but for this example
    // we're going to show the full exception
    die("<html><head><title>SEARCH EXCEPTION</title><body><pre>{$e->__toString()}</pre></body></html>");
  }

  if ($results) {
    print_r($results);
  }
}

SolrSearch("cats");

