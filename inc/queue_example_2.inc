<?php

/**
 * Multiple operations and context.
 */

/**
 * Form callback.
 */
function batch_example_2($form, &$form_state) {
  $form['textarea'] = array(
    '#type' => 'textarea',
    '#default_value' => "http://www.google.com/\nhttp://www.pudim.com.br"
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Example 1',
  );
  
  return $form;
}

/**
 * Form submit.
 */
function batch_example_2_submit($form, &$form_state) {
  // Get form values.
  $urls = explode(PHP_EOL, $form_state['values']['textarea']);

  // Batch with params.
  $batch = array(
    'operations' => array(
      array('batch_example_2_operation_get_content', array($urls)),
      array('batch_example_2_operation_zip_content', array()),
    ),
    'file' => drupal_get_path('module', 'batch_example') . '/inc/batch_example_2.inc'
  );

  // Set and process it.
  batch_set($batch);
  batch_process();
}

/**
 * Operation will get the url data.
 */
function batch_example_2_operation_get_content($urls, $context) {

  // Identifying the first time.
  if (!isset($context['sandbox']['count'])) {
    $context['message'] = t('Operation initialized.');

    // These values are accessible to this function
    // during the iterations.
    $context['sandbox']['count'] = -1;
    $context['sandbox']['total'] = sizeof($urls);
  }

  // Counter.
  $context['sandbox']['count'] ++;

  // Finish the operation.
  if (!isset($urls[$context['sandbox']['count']])) {
    $context['finished'] = 1;
    $context['message'] = t('Operation finished.');
    return;
  }

  // Get the url.
  $url = $urls[$context['sandbox']['count']];
  $context['message'] = t('Trying to get the content of %url.', array('%url' => $url));

  // Store each result.
  $context['results'][] = drupal_http_request($url);
  
  // This function will execute again.
  $context['finished'] = 0;
}

/**
 * Operation to save the content in a zip file.
 */
function batch_example_2_operation_zip_content($context) {
  dpm($context);
}