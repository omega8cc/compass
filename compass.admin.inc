<?php
// $Id$

/**
 * @file
 * Compass module admin settings.
 */

/**
 * Settings form for the toolkit.
 */
function compass_settings_form() {
  $form = array();
  $form['compass_binary'] = array(
    '#type' => 'fieldset',
    '#title' => t('Compass Binary'),
    '#collapsible' => FALSE,
    '#description' => t('Compass is a standalone Ruby script used to compile CSS from Sass stylesheets. To use it, it must be installed on your server and you need to know where it is located. If you are unsure of the exact path consult your ISP or server administrator.'),
  );
  $form['compass_binary']['version'] = array('#weight' => -1);
  $form['compass_binary']['#after_build'] = array('_compass_build_version');
  $form['compass_binary']['compass_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path of "compass" executable'),
    '#default_value' => variable_get('compass_path', '/usr/bin/compass'),
    '#required' => TRUE,
    '#description' => t('Specify the complete path to the Compass binary. For example: <kbd>/usr/bin/compass</kbd>'),
    '#element_validate' => array('compass_validate_path'),
  );
  $form['compass_binary']['compass_debugging'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display debugging information'),
    '#default_value' => variable_get('compass_debugging', 0),
    '#description' => t('Checking this option will display the Compass commands and output to users with the <em>administer site configuration</em> permission.'),
    '#weight' => 2,
  );
  $form['compass_output_style'] = array(
    '#type' => 'radios',
    '#title' => 'Output Style',
    '#options' => array(
      'nested' => 'Nested',
      'expanded' => 'Expanded',
      'compact' => 'Compact',
      'compressed' => 'Compressed',
    ),
    '#default_value' => variable_get('compass_output_style', 'nested'),
  );
  $form['compass_environment'] = array(
    '#type' => 'radios',
    '#title' => 'Output Style',
    '#options' => array(
      'development' => 'Development',
      'production' => 'Production',
    ),
    '#description' => 'Use sensible defaults for your current environment.',
    '#default_value' => variable_get('compass_environment', 'production'),
  );
  $form['compass_relative_assets'] = array(
    '#type' => 'checkbox',
    '#title' => 'Relative Assets',
    '#description' => 'Indicates whether the compass helper functions should generate relative urls from the generated css to assets, or absolute urls using the http path for that asset type.',
    '#default_value' => variable_get('compass_relative_assets', FALSE)
  );
  $form['compass_cron'] = array(
    '#title' => 'Run <em>compass</em> during cron tasks',
    '#type' => 'checkbox',
    '#default_value' => variable_get('compass_cron', TRUE),
  );
  return system_settings_form($form);
}
