<?php

function nypl_collections_admin_settings() {

  $form['collections_api_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collections API Settings'),
  );

  $form['collections_api_settings']['collections_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('NYPL Collections API Key'),
    '#default_value' => variable_get('collections_api_key', '8ostlxoc8dq0uat9'),
    '#description' => t('Collections API Key. Register ' . l('here.','http://api.repo.nypl.org/sign_up')),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
