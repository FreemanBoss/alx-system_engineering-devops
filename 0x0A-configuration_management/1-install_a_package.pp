# install flask from pip3
# Requirements:
# Install flask
# Version must be 2.1.0

package { 'flask':
  ensure   => '2.1.0',
  name     => 'flask',
  provider => 'pip3',
}

package { 'werkzeug':
  ensure   => '2.1.1',
  provider => 'pip3',
}
