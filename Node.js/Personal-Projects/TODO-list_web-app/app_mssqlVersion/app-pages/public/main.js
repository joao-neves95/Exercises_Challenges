'use strict'

let currentPage = 'home';

let postItems;
let updateItem;
let deleteItem;
let getItems;
let getItem;
let updateItemClick;

$('document').ready(() => {

  // UTILS:
  const hasClass = (el, selector) => {
    let className = " " + selector + " "
    return (" " + el.className + " ").replace(/[\n\t]/g, " ").indexOf(className) > -1
  }

  const boolToInt = (val) => {
    if (val === true)
      return 1;
    return 0;
  }

  // HTML:
  const userItemCards = (json) => {
    return `<a href="#" class="list-group-item list-group-item-action flex-column align-items-start" onclick="updateItemClick('${json.Item_Id}'); return false">
             <div class="d-flex w-100 justify-content-between">
               <h5 class="mb-1">${json.Title}</h5>
               <div>
                 <button class="btn btn-danger btn-sm btn-floating float-right ml-1" id="delete-item" onclick="deleteItem('${json.Item_Id}'); getItems(); return false" aria-label="Close">
                   <span aria-hidden="true">&times;</span>
                 </button>
               </div>
             </div>
             <p class="mb-1">${json.Description}</p>
           </a>`
  }

  const communityItemCards = (json) => {
    return `<a href="#" class="list-group-item list-group-item-action flex-column align-items-start" onclick="">
             <div class="d-flex w-100 justify-content-between">
               <h5 class="mb-1">${json.Title}</h5>
               <div>
                 <button class="btn btn-danger btn-sm btn-floating float-right ml-1" id="delete-item" onclick="" aria-label="Close">
                   <span aria-hidden="true">&times;</span>
                 </button>
               </div>
             </div>
             <p class="mb-1">${json.Description}</p>
           </a>`
  }

  // RESTFUL API AJAX REQUESTS:
  postItems = (formData) => {
    $.ajax({
      url: 'http://localhost:3000/api/items',
      dataType: 'json',
      type: 'POST',
      method: "POST",
      data: formData,
      processData: true,
      success: () => { getItems('user') },
      error: (jqXHR, textStatus, errorThrown) => {
        console.log(`jqXHR: ${jqXHR.message}`);
        console.log(`textStatus: ${textStatus}`);
        console.log(`errorThrown: ${errorThrown}`);
      },
    })
  }

  updateItem = (formData, id) => {
    $.ajax({
      url: 'http://localhost:3000/api/item?id=' + id,
      dataType: 'json',
      type: 'PUT',
      method: "PUT",
      data: formData,
      processData: true,
      success: () => { getItems('user') },
      error: (jqXHR, textStatus, errorThrown) => {
        console.log(`jqXHR: ${jqXHR.message}`);
        console.log(`textStatus: ${textStatus}`);
        console.log(`errorThrown: ${errorThrown}`);
      },
    })
  }

  deleteItem = (id) => {
    $.ajax({
      url: 'http://localhost:3000/api/items?id=' + id,
      type: 'DELETE',
      contentType: "application/json",
      success: () => { getItems('user') },
      error: (jqXHR, textStatus, errorThrown) => {
        console.log(`jqXHR: ${jqXHR.message}`);
        console.log(`textStatus: ${textStatus}`);
        console.log(`errorThrown: ${errorThrown}`);
      }
    })
  }

  getItems = (type) => {
    let apiLink;
    const userItemsApi = 'http://localhost:3000/api/items';
    const communityItemsApi = 'http://localhost:3000/api/community-items';

    if (type === 'user')
      apiLink = userItemsApi;
    else if (type === 'community')
      apiLink = communityItemsApi;

    $.ajax({
      url: apiLink,
      dataType: 'json',
      type: 'GET',
      contentType: 'application/json; charset=UTF-8',
      success: (json) => {
        document.getElementById('items-cards-holder').innerHTML = ''
        if (type === 'community') {
          for (let i = 0; i < json.length; i++) {
            document.getElementById('items-cards-holder').innerHTML += communityItemCards(json[i]);
          }
        } else {
          for (let i = 0; i < json.length; i++) {
            document.getElementById('items-cards-holder').innerHTML += userItemCards(json[i]);
          }
        }
      },
      error: (jqXHR, textStatus, errorThrown) => {
        console.log(`jqXHR: ${jqXHR.message}`);
        console.log(`textStatus: ${textStatus}`);
        console.log(`errorThrown: ${errorThrown}`);
      }
    })
  }

  getItem = (id, callback) => {
    $.ajax({
      url: 'http://localhost:3000/api/item?id=' + id,
      dataType: 'json',
      type: 'GET',
      contentType: 'application/json; charset=UTF-8',
      success: (json) => {
        callback(json)
      },
      error: (jqXHR, textStatus, errorThrown) => {
        console.log(`jqXHR: ${jqXHR.message}`);
        console.log(`textStatus: ${textStatus}`);
        console.log(`errorThrown: ${errorThrown}`);
      }
    })
  }
  // End of RESTFUL API AJAX REQUESTS.

  // INITIALIZATION:
  $('#add-item-window').slideUp()
  document.getElementById('method').value = 'POST'
  getItems('user')

  // Initialize the Pickadate.js plugin:
  $('#datepicker').pickadate().get()
  $('#timepicker').pickatime().get()

  // HEADER BUTTON "New Item" DROP-DOWN ('click' EVENT):
  document.getElementById('btn-new-item').addEventListener('click', () => {
    if (!hasClass(document.getElementById('btn-new-item'), 'active')) {
      document.getElementById('btn-new-item').classList.add('active')
      document.getElementById('add-item-window').style.display = ''
      document.getElementById('add-item-window').style.visibility = 'visible'
      $('#add-item-window').slideDown()
    } else {
      document.getElementById('btn-new-item').classList.remove('active')
      $('#add-item-window').slideUp()
    }
  })
  // End of BUTTON "New Item".

  // UPDATE ITEM ON ITEM CLICK EVENT (It puts the item data on the form and sets hidden method to 'PUT').
  updateItemClick = (id) => {
    // Change the hidden "method" input from the "New Item" form:
    // When the user clicks "SAVE", it checks the hidden "method" input -> 'PUT' / 'POST').
    document.getElementById('method').value = 'PUT'

    getItem(id, (json) => {
      // Insert the item data on the "New Item" form:
      document.getElementById('title').value = json[0].Title
      document.getElementById('itemId').value = id // Store the item id on an hidden input on the "New Item" form.
      document.getElementById('priority').options.selectedIndex = json[0].Priority - 1;
      document.getElementById('description').value = json[0].Description;
      document.getElementById('datepicker').value = json[0].DueDate;
      document.getElementById('timepicker').value = json[0].DueTime;
      document.getElementById('isPublic').checked = json[0].IsPublic;

      // Show the "New Item" form:
      document.getElementById('btn-new-item').classList.add('active');
      document.getElementById('add-item-window').style.display = '';
      document.getElementById('add-item-window').style.visibility = 'visible';
      $('#add-item-window').slideDown()
    })
  }

  // BUTTON "Save" ON THE "New Item" FORM ('click' EVENT):
  // It is used to POST and PUT items (that's why there are 2 chained if statements)
  document.getElementById('btn-save-item').addEventListener('click', () => {
    if (document.getElementById('title').value === '') {
      return null;
    } else {
      let formData = {
        "title": document.getElementById('title').value,
        "priority": (document.getElementById('priority').options.selectedIndex + 1).toString(),
        "description": document.getElementById('description').value,
        "dueDate": document.getElementById('datepicker').value,
        "dueTime": document.getElementById('timepicker').value,
        "isPublic": boolToInt(document.getElementById('isPublic').checked)
      }

      if (document.getElementById('method').value === 'PUT') {
        updateItem(formData, document.getElementById('itemId').value);
        // Make the hidden input (AJAX method type) POST again:
        document.getElementById('method').value = 'POST';
      } else if (document.getElementById('method').value === 'POST') {
        postItems(formData);
      }

      // HIDE THE "New Item" FORM:
      document.getElementById('btn-new-item').classList.remove('active')
      $('#add-item-window').slideUp();

      // Clean form values:
      document.getElementById('title').value = '';
      document.getElementById('title').value = '';
      document.getElementById('priority').options.selectedIndex = 2;
      document.getElementById('description').value = '';
      document.getElementById('datepicker').value = '';
      document.getElementById('timepicker').value = '';
      document.getElementById('isPublic').checked = false;
    }
  })
  // End of BUTTON "Save".

  // HOME BUTTON:
  document.getElementById('btn-home').addEventListener('click', () => {
    if (currentPage === 'home')
      return null;

    currentPage = 'home';
    getItems('user');
  })

  // COMMUNITY ITEMS BUTTON:
  document.getElementById('btn-comunityItems').addEventListener('click', () => {
    if (currentPage === 'communityItems')
      return null;

    currentPage = 'communityItems';
    getItems('community');
  });
})
