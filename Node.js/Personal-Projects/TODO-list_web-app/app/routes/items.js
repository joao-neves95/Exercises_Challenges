'use strict'

module.exports = {
  getItems (req, res) {
    res.locals.db.collection('items')
      .find( {} )
      .toArray((err, items) => {
        if (err)
          throw err

        res.status(200).send(items)
      })
  },

  getItem (req, res) {
    res.locals.db.collection('items')
      .find( {"_id": mongoDB.ObjectId(req.query.id)} )
      .toArray((err, item) => {
        if (err)
          throw err

        res.status(200).send(item)
      })
  },

  postItem (req, res) {
    res.locals.db.collection('items')
      .insertOne(req.body, (err, results) => {
      if (err)
        throw err

      res.status(201).send(results)
      })
  },

  updateItem (req, res) {
    res.status(200).send()
  },

  deleteItem (req, res) {
    res.locals.db.collection('items')
      .deleteOne( {"_id": mongoDB.ObjectId(req.query.id)}, (err, results) => {
        if (err)
         throw err

        console.log(req.query.id)
        res.status(200).send(results)
      })
  }
}
