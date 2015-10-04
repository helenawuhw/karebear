var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

/* GET Hello World page. */
router.get('/login', function(req, res) {
    res.render('login', { title: 'Hello, World!' });
});

module.exports = router;
