#Basic Usage
===
###### Stats

Display databases

```
show dbs
```

###### Create Database
```
use testdb
```

###### Collection
Show all collections in current database

```
show collections
```

Create Collection
`option` parameter is optional, it is used to specify the configuration of the collection

```
db.createCollection(name, options)
```

Drop Collection

```
db.COLLECTION_NAME.drop()
```

###### Insert Data
```
db.collection_name.insert(
	{
		name: 'meow',
		gender: 'male',
		age: 10
		description: 'French Cat'
	}
)
```

In the inserted document if we don't specify the _id parameter, then MongoDB assigns an unique ObjectId for this document.

`_id` is 12 bytes hexadecimal number unique for every document in a collection. 12 bytes are divided as follows `_id: ObjectId(4 bytes timestamp, 3 bytes machine id, 2 bytes process id, 3 bytes incrementer)`

###### Query Data
Display Data (Unstructured way)

```
db.COLLECTION_NAME.find()
```
Display Data (Structured Way)

```
db.COLLECTION_NAME.find().pretty()
```

##### Conditions

Equality	`{<key>:<value>}`

```
db.mycol.find({"name": "sarah"}).pretty()
```

Less Than			`{<key>:{$lt:<value>}}` 	<br>
Less Than Equals	`{<key>:{$lte:<value>}}` 	<br>
Greater Than		`{<key>:{$gt:<value>}}` 	<br>
Greater Than Equals	`{<key>:{$gte:<value>}}` 	<br>
Not Equals 			`{<key>:{$ne:<value>}}` 	<br>

```
db.mycol.find({'likes':{$lt: 500}}).pretty()
```

<b>AND</b> in MongoDB

```
db.mycol.find({key1: value1, key2: value2}).pretty()
>
> db.mycol.find({name:'sarah', age: 27}).pretty()
{
   "_id": ObjectId(7df78ad8902c),
   "name": "sarah",
   "age": 27
}
```


<b>OR</b> in MongoDB

```
db.mycol.find(
	{
		$or: [
			{key1: value1},
			{key2: value2}
		]
	}
)
```
<b>Update</b>

```
db.collection_name.update(selection_criteria, updated_data)
```
e.g.

```
db.mycol.update({'title':'President'}, {$set{'description': 'very important'}})
```

<b>Save()</b> Method <br>
Replace the document with the _id '5983548781331adf45ec7'

```
db.Collection_name.save({_id:Object_ID, NEW_DATA})
```

e.g.

```
db.mycol.save(
	{
		"_id" : ObjectId(5983548781331adf45ec7), 
		"title":"Tutorials Point New Topic",
        "by":"Tutorials Point"
	}
)
```



<b>Limit Result</b> <br>
Set a limit to num of result returned

```
e.g.
limit the num of result returned to be 1
-
db.collection.find().limit(1)
```


<b>Compare ObjectID</b> <br>
Find an document less than an object ID

```
db.collection.find({_id:{$lt:ObjectID("dhsb8sb322hbqn1913m")}})
```

<b>Add to array</b> <br>
Add new element to an array

```
db.students.update(
   { _id: 1 },
   { $push: { scores: 89 } }
)
```

<b>Sort</b> <br>
Sort according to datafield

```
1: oldest first
-1: newest first
db.find().sort({<datafiled>:1})
```








