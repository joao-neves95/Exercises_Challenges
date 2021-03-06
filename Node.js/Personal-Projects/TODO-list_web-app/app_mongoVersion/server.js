'use strict';
require('dotenv').config();
const express = require('express');
const path = require('path');
const helmet = require('helmet');
const sessionsConfig = require('./middleware/sessions');
const authenticationConfig = require('./middleware/authentication');
const bodyParser = require('body-parser');
const compression = require('compression');
const logger = require('morgan');
const routes = require('./routes/index.js');
global.mongoDB = require('mongodb');
const URI = 'mongodb://localhost:27017/todo-list_web-app';
const app = express();

app.use(logger('dev'));
app.use(helmet());
app.use(compression());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Serve Public FrontPage and static files:
app.use('/', express.static(path.join(__dirname, './public')));

mongoDB.MongoClient.connect(URI, (err, database) => {
  if (err)
    return process.exit(1);

  console.log('Database connection successful.');
  const DB = database.db('todo-list_web-app');

  // Use the MongoDB present connection across the router:
  app.use((req, res, next) => {
    req.db = DB;
    next();
  });

  sessionsConfig(app);
  authenticationConfig(app, DB);

  // ROUTES:
  app.use('/', routes);

  const PORT = process.env.PORT || 3000;
  app.listen(PORT, () => {
    console.log(`Listening on port ${PORT}`);
  });
});
