<?php

function nypl_collections_admin_settings() {
  // url = "http://api.repo.nypl.org/api/v1/items/8568ccd0-c614-012f-1d74-58d385a7bc34.xml"

  $form['collections_api_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collections API Settings'),
  );

  $form['collections_api_settings']['collections_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('NYPL Collections API Key'),
    '#default_value' => variable_get('collections_api_key', '8ostlxoc8dq0uat9'),
    '#description' => t('Collections API Key. Register ' . l('here','http://api.repo.nypl.org/sign_up') . '.'),
    '#required' => TRUE,
  );

  $form['collections_api_settings']['collections_api_version'] = array(
    '#type' => 'textfield',
    '#title' => t('NYPL Collections API Version'),
    '#default_value' => variable_get('collections_api_version', 'v1'),
    '#description' => t('NYPL Collections API Version'),
    '#required' => TRUE,
  );

  $form['repo_solr_settings']['host'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr Host URI'),
    '#default_value' => variable_get('solr_host_uri', 'http://solr.farm.nypl.org/'),
    '#description' => t('NYPL Repo Solr Host'),
    '#required' => TRUE,
  );

  $form['repo_solr_settings']['port'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr Host Port'),
    '#default_value' => variable_get('solr_host_port', '8080'),
    '#description' => t('NYPL Repo Solr Port'),
    '#required' => TRUE,
  );

  $form['repo_solr_settings']['version'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr version'),
    '#default_value' => variable_get('solr_host_version', 'solr-3.5'),
    '#description' => t('NYPL Repo Version'),
    '#required' => TRUE,
  );
  
  $form['repo_solr_settings']['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr password'),
    '#default_value' => variable_get('solr_host_pass', 'WbVL2ji5fNdstUrUHDdu'),
    '#description' => t('NYPL Collections API Version'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
