<?php

require_once('solr-php-client/Apache/Solr/Service.php');

define('SOLR_URI','solr.farm.nypl.org');
define('SOLR_PORT','8080');
define('SOLR_VERSION','/solr-3.5/repoapi');
define('SOLR_USER','solradmin');
define('SOLR_PASS','WbVL2ji5fNdstUrUHDdu');

// Example: http://solr.farm.nypl.org:8080/solr-3.5/repoapi/select/?q=*%3A*&start=0&rows=0&facet=true&facet.field=topic_mtxt_s&facet.limit=1200

function SolrSearch($query) {
  $solr = new Apache_Solr_Service(SOLR_URI, SOLR_PORT, SOLR_VERSION);
  $solr->setAuthenticationCredentials(SOLR_USER, SOLR_PASS);
  $limit = 500;

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
    die("<html><head><title>SEARCH EXCEPTION</title><body><pre>{$e->__toString()}</pre></body></html>");
  }

  if ($results) {
	return $results;
  }
}

function SolrSearchFacets($query, $facet) {
  $solr = new Apache_Solr_Service(SOLR_URI, SOLR_PORT, SOLR_VERSION);
  $solr->setAuthenticationCredentials(SOLR_USER, SOLR_PASS);
  $limit = 30;
  if (!$solr->ping()) {
    print 'Solr service not responding.';
    die();
  }

  if (get_magic_quotes_gpc() == 1) {
    $query = stripslashes($query);
  }

  try {
    $params = array(
      'facet' => 'true',
      'facet.field' =>  $facet,
      'facet.limit' => 30
    );

    $results = $solr->search($query, 0, $limit, $params);
  }
  catch (Exception $e) {
    die("<html><head><title>SEARCH EXCEPTION</title><body><pre>{$e->__toString()}</pre></body></html>");
  }

  if ($results) {
	return $results;
  }
}




?>

